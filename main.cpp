#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <json/json.h> // Include JSON library (Install if needed)

void fetchGitHubActivity(const std::string& username) {
    std::string command = "powershell -Command \"Invoke-WebRequest -Uri 'https://api.github.com/users/" 
                          + username + "/events' -OutFile github_activity.json\"";
    std::system(command.c_str()); // Fetch API data and store in JSON file

    std::ifstream file("github_activity.json");
    if (!file) {
        std::cerr << "Error: Failed to open the JSON file.\n";
        return;
    }

    Json::Value jsonData;
    Json::CharReaderBuilder reader;
    std::string errors;

    if (!Json::parseFromStream(reader, file, &jsonData, &errors)) {
        std::cerr << "Error parsing JSON: " << errors << std::endl;
        return;
    }

    std::cout << "Recent GitHub Activity for " << username << ":\n";

    for (const auto& event : jsonData) {
        std::string eventType = event["type"].asString();
        std::string repoName = event["repo"]["name"].asString();
        std::string createdAt = event["created_at"].asString();

        std::cout << "\nEvent Type: " << eventType
                  << "\nRepository: " << repoName
                  << "\nTimestamp: " << createdAt << "\n";

        if (eventType == "PushEvent") {
            for (const auto& commit : event["payload"]["commits"]) {
                std::string commitMessage = commit["message"].asString();
                std::string commitURL = commit["url"].asString();

                std::cout << "Commit: " << commitMessage
                          << "\nCommit URL: " << commitURL << "\n";
            }
        }
    }
}

int main() {
    std::string username;
    std::cout << "Enter GitHub username: ";
    std::getline(std::cin, username);

    fetchGitHubActivity(username);
    return 0;
}
