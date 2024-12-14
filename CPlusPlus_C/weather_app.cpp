#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;

// Function to make HTTP GET request
std::string makeGetRequest(const std::string& url);

// Function to parse the weather data JSON and extract temperature, wind speed, and pressure
void parseWeatherData(const std::string& jsonStr, const std::string& date, double& temp, double& windSpeed, double& pressure);

int main() {
    std::string apiKey = "b6907d289e10d714a6e88b30761fae22";
    std::string location = "London,us";

    std::string apiUrl = "https://samples.openweathermap.org/data/2.5/forecast/hourly?q=" + location + "&appid=" + apiKey;

    int option;
    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Get weather" << std::endl;
        std::cout << "2. Get Wind Speed" << std::endl;
        std::cout << "3. Get Pressure" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cin >> option;

        if (option == 0) {
            break;
        } else if (option >= 1 && option <= 3) {
            std::string date;
            std::cout << "Enter the date (format: YYYY-MM-DD HH:MM:SS): ";
            std::cin.ignore();
            std::getline(std::cin, date);

            std::string response = makeGetRequest(apiUrl);
            double temp, windSpeed, pressure;
            parseWeatherData(response, date, temp, windSpeed, pressure);

            switch (option) {
                case 1:
                    std::cout << "Temperature on " << date << ": " << temp << "°C" << std::endl;
                    break;
                case 2:
                    std::cout << "Wind Speed on " << date << ": " << windSpeed << " m/s" << std::endl;
                    break;
                case 3:
                    std::cout << "Pressure on " << date << ": " << pressure << " hPa" << std::endl;
                    break;
            }
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}

// Function to make HTTP GET request
std::string makeGetRequest(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* ptr, size_t size, size_t nmemb, std::string* data) {
            data->append(ptr, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error while making HTTP request: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

// Function to parse the weather data JSON and extract temperature, wind speed, and pressure
void parseWeatherData(const std::string& jsonStr, const std::string& date, double& temp, double& windSpeed, double& pressure) {
    json jsonData = json::parse(jsonStr);

    for (const auto& entry : jsonData["list"]) {
        std::string entryDate = entry["dt_txt"];
        if (entryDate.find(date) != std::string::npos) {
            temp = entry["main"]["temp"];
            windSpeed = entry["wind"]["speed"];
            pressure = entry["main"]["pressure"];
            return;
        }
    }

    // If the date is not found in the response
    temp = windSpeed = pressure = -1;
}
