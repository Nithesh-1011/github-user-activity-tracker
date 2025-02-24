# GitHub User Activity Fetcher

Sample solution for the [github-user-activity](https://roadmap.sh/projects/github-user-activity) challenge from [roadmap.sh](https://roadmap.sh/).

## Overview
This C++ program fetches and displays a user's recent GitHub activity using the GitHub API. It retrieves event details such as event type, repository name, timestamps, and commit messages for push events.

## Features
- Fetches recent GitHub events for a given username.
- Extracts details such as event type, repository name, and timestamps.
- Displays commit messages and URLs for push events.
- Uses `jsoncpp` for JSON parsing.
- Runs PowerShell command to fetch API data.

## Prerequisites
- **C++ Compiler** (GCC, Clang, or MSVC)
- **jsoncpp Library** (Install if not already available)
- **PowerShell** (Required for executing the API request on Windows)

## Installation & Setup
### 1. Install `jsoncpp`
#### **For Linux (Ubuntu/Debian)**:
```bash
sudo apt-get install libjsoncpp-dev
```
#### **For macOS**:
```bash
brew install jsoncpp
```
#### **For Windows (MSYS2)**:
```bash
pacman -S mingw-w64-x86_64-jsoncpp
```

### 2. Clone the Repository
```bash
git clone https://github.com/Nithesh-1011/github-user-activity.git
cd github-user-activity
```

### 3. Compile the Program
```bash
g++ -o github_activity main.cpp -ljsoncpp
```

### 4. Run the Program
```bash
./github_activity
```

## Usage
1. **Enter the GitHub username** when prompted.
2. **Wait for the program to fetch the data.**
3. **View the recent GitHub activity, including commits for push events.**

## Example Output
```
Enter GitHub username: Nithesh-1011

Recent GitHub Activity for Nithesh-1011:

Event Type: PushEvent
Repository: Nithesh-1011/cli-task-tracker
Timestamp: 2025-02-24T09:23:08Z
Commit: Update README.md
Commit URL: https://api.github.com/repos/Nithesh-1011/cli-task-tracker/commits/dd3b3f440b17d277ac767acd7654867e3ffabde7
```

## Limitations
- Requires an internet connection.
- GitHub API rate limits unauthenticated requests.
- Only fetches public activity.

## License
This project is licensed under the MIT License.

## Author
**Srinithesh A**  
GitHub: [Nithesh-1011](https://github.com/Nithesh-1011)

