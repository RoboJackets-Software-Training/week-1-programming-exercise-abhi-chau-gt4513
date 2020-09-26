//Do not edit the next 4 lines
#include <iostream>
#include <vector>

int main() {
	std::cout << "Use the wasd keys and enter to input a direction, or the E key to stop" << std::endl;

    // Step 1: 4 floats for wheel speeds
    std::vector<float> wheel_speeds(4);

    // Step 2: Set each wheelSpeeds element to 0.0.
    wheel_speeds[0] = 0;
    wheel_speeds[1] = 0;
    wheel_speeds[2] = 0;
    wheel_speeds[3] = 0;
   
    // Do not edit the next 5 lines
    bool keep_going = true;
    char direction;

    while (keep_going) {
        std::cin >> direction; //At the begining of every iteration look for an input from the user
        
        // If else-if statements
        if (direction == 'w') {

            for (int i = 0; i < 4; i++) {
                wheel_speeds[i] = 1;
            }

        } else if (direction == 'a') {

            wheel_speeds[0] = 0.5;
            wheel_speeds[1] = 1;
            wheel_speeds[2] = 0.5;
            wheel_speeds[3] = 1;

        } else if (direction == 's') {
            
            for (int i = 0; i < 4; i++) {
                wheel_speeds[i] = -1;
            }

        } else if (direction == 'd') {

            wheel_speeds[0] = 1;
            wheel_speeds[1] = 0.5;
            wheel_speeds[2] = 1;
            wheel_speeds[3] = 0.5;
            
        } else if (direction == 'e') {

            for (int i = 0; i < 4; i++) {
                wheel_speeds[i] = 0;
            }
            std::cout << "Shutting down" << std::endl;
            keep_going = false;
            
        } else {

            std::cout << "Sorry, I didn't get that. Try again." << std::endl;

        }

        for (int i = 0; i < 4; i++) {
                std::cout << "Wheel at index " << i << " has speed: " << wheel_speeds[i] << std::endl;
        }

    }

    return 0;

}
