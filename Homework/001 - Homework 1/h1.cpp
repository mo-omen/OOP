#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <stdlib.h>

using namespace std;

const float PI = 3.1415927f;
const float G = 9.81f;

void clearLine();
void clearScreen();
float readFloat(string prompt);
void printBanner();

float toRad(float deg);
float timeOfFlight(float v, float theta_rad);
float maxHeight(float v, float theta_rad);
float range(float v, float theta_rad);
float yAtX(float v, float theta_rad, float x);

void printResults(float v, float theta_deg, float x);

int main() {
    system("clear");
    printBanner();

    float v = readFloat("Enter the initial speed of the plate (m/s) : ");
    float theta_deg = readFloat("Enter the launch angle of the plate (0-90 degrees) : ");
    float x = readFloat("Enter the distance of Aiman (m): ");

    cout << '\n';
    printResults(v, theta_deg, x);

    return 0;
}

void clearLine() {
    cout << string(60, '-') << '\n';
}

void clearScreen() {
    cout << "\033[2J\033[H";
}

float readFloat(string prompt) {
    float val;
    cout << prompt;
    cin >> val;
    return val;
}

void printBanner() {
    clearScreen();
    clearLine();
    cout << "Harith threw a nasi lamak plate at Aiman....\n";
    clearLine();
    cout << '\n';
}

float toRad(float deg) {
    return deg * PI / 180.0f;
}

float timeOfFlight(float v, float theta_rad) {
    return 2.0f * v * sin(theta_rad) / G;
}

float maxHeight(float v, float theta_rad) {
    float vy = v * sin(theta_rad);
    return (vy * vy) / (2.0f * G);
}

float range(float v, float theta_rad) {
    return (v * v) * sin(2.0f * theta_rad) / G;
}

float yAtX(float v, float theta_rad, float x) {
    float cosT = cos(theta_rad);
    if (abs(cosT) < 0.0001f) {
        return -1.0f;
    }
    float R = range(v, theta_rad);
    if (x < 0.0f || x > R) {
        return -1.0f;
    }
    return x * tan(theta_rad) - (G * x * x) / (2.0f * v * v * cosT * cosT);
}

void printResults(float v, float theta_deg, float x) {
    system("clear");
    float theta = toRad(theta_deg);
    float T = timeOfFlight(v, theta);
    float H = maxHeight(v, theta);
    float R = range(v, theta);
    float y = yAtX(v, theta, x);

    clearLine();
    cout << "RESULTS  (v = " << v << " m/s,  theta = " << theta_deg << " degrees,  x = " << x << " m)\n";
    clearLine();
    cout << fixed << setprecision(4);
    cout << "- Time of flight = " << T << " s\n";
    cout << "- Maximum height = " << H << " m\n";
    cout << "- Horizontal range = " << R << " m\n";

    if (y < 0.0f) {
        cout << "- Aiman didn't get hit [Try again bruh ( •̀ ω •́ )👎]\n";
    } else {
        cout << "- Aiman got hit at y = " << y << " m [Nice shot bruh ( •̀ ω •́ )👍]\n";
    }
}
