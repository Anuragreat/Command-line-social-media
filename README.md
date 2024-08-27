
# Command-Line Social Media App

This is a simple command-line social media application written in C++. The app allows users to create profiles, follow each other, post messages, and view a personalized feed based on the posts of the users they follow. The project demonstrates object-oriented programming concepts and the basics of user interaction in C++.

## Features

- **User Profiles**: Create new users with unique usernames.
- **Follow Other Users**: Users can follow one another...
- **Create Posts**: Users can create posts that are stored under their profiles.
- **View Feed**: Users can view a feed of posts made by the users they follow.

## Project Structure

The project is structured around three main classes:
1. **Post**: Represents individual posts with content and username.
2. **User**: Represents users with functionalities such as following other users and creating posts.
3. **SocialMediaApp**: Manages the overall application, including user creation, following, posting, and displaying feeds.

## How to Run

### Requirements

- C++ Compiler (e.g., g++, clang++)
  
### Steps

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/command-line-social-media-app.git
   cd command-line-social-media-app
   ```

2. **Compile the code**:
   ```bash
   g++ main.cpp -o social_app
   ```

3. **Run the application**:
   ```bash
   ./social_app
   ```

4. **Interact with the app**: You can create users, have them follow each other, make posts, and view their feed through the terminal.

## Example Usage

```bash
User Abhinav created successfully!
User Ishant created successfully!
User Anubhav created successfully!

Abhinav is now following Ishant!
Abhinav is now following Anubhav!
Ishant is now following Anubhav!

Ishant created a new post!
Anubhav created a new post!
Anubhav created a new post!

--- Abhinav's Feed ---
Ishant: Hello from Ishant!
Anubhav: Hey, Anubhav here!
Anubhav: Good morning everyone!
```

## Possible Enhancements

- Add file handling to save user data and posts between sessions.
- Implement more advanced features like liking posts, commenting, or direct messaging.
- Add a user authentication system.
- Use threading for real-time notifications or chat features.

## Contribution

Feel free to fork this repository and contribute to it. Submit your issues or pull requests if you’d like to improve or extend the project.

