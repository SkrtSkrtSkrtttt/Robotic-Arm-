# Robotic Arm Project

This project focuses on designing and building a functional robotic arm using 3D-printed parts and embedded control logic. The system integrates mechanical design, electronics, and software to achieve articulated motion. The robotic arm is intended as a hands-on platform for applying foundational engineering concepts, including component interfacing, motion control, and system integration.

## Objective

- Design and build a robotic arm that demonstrates controlled movement.
- Apply classroom concepts in CAD modeling, embedded systems, and circuit design.
- Manage the project as a team using engineering best practices.

## Project Management

- Team-based collaboration with assigned roles
- Gantt chart used to plan and track tasks over a 2-week timeline
- Follows a structured process across design, implementation, and documentation phases

---

## Phase 1: Mechanical Design

- Use Autodesk Inventor to construct the full 3D model of the robotic arm
- Download STEP/CAD files of all necessary components
- Design and model custom parts using parametric tools
- 3D print the robotic arm components
- Assemble the full mechanical system based on the modeled structure

## Phase 2: Electronics & Software

- Collect datasheets and identify pinouts for all electronic components (e.g. servos, sensors)
- Test individual components using a multimeter and power supply
- Create a TinkerCAD simulation of the full system
- Write testing programs to verify component functionality
- Implement movement control logic (e.g., joint positioning, driving modes)
- Test and refine the functions to ensure reliable behavior
- Wire and program the full robotic arm system
- Evaluate performance and iterate as necessary

## Phase 3: Documentation & Presentation

A complete project report was produced including:
- Design overview and concept development
- 3D models and technical drawings
- Exploded views and mechanical assembly instructions
- System architecture and circuit schematics
- Wire harness diagrams and embedded code
- Troubleshooting guide
- Bill of Materials (BOM) and references

Additionally, a 12-slide PowerPoint presentation was created summarizing:
- Team roles and project objectives
- CAD modeling process
- System design and control logic
- Key challenges and solutions
- Final demo (video may be unavailable)

  ## Code Overview

The robotic arm is controlled using an IR remote and four servo motors, each responsible for a different part of the arm:

- **Base rotation**
- **Lower arm**
- **Upper arm**
- **Gripper**

The Arduino reads IR remote signals and interprets them using the `IRremote` library to increment or decrement the movement state of each servo.

### Key Components:
- `Servo.h` — Used to control four servos via PWM
- `IRremote.h` — Used to decode input from an IR remote
- Serial output is used for debugging and monitoring state changes

### Controls (Mapped IR Codes):
| Remote Button | Action                         |
|---------------|--------------------------------|
| 0             | Increase base angle            |
| 7             | Decrease base angle            |
| 1             | Raise lower & upper arm        |
| 4             | Lower lower & upper arm        |
| 2             | Open gripper                   |
| 5             | Close gripper                  |
| *             | Decrease speed multiplier      |
| #             | Increase speed multiplier      |

Each component responds proportionally to a configurable `multi` value, which acts as a speed/step multiplier.

The robotic arm supports:
- Fine-grain control of angles (0°–180°)
- Smooth movement via timed `delay()` between position updates
- Bidirectional movement for each joint
- Resettable multipliers to control speed/responsiveness

The code is written in Arduino C and leverages real-time IR command parsing inside the `loop()` function.


## Technologies & Tools Used

- Autodesk Inventor (CAD modeling)
- Arduino (Microcontroller platform)
- TinkerCAD (Circuit simulation)
- Arduino C / Embedded C
- 3D Printer (Mechanical part fabrication)
- Multimeter & Power Supply (Component testing)

## Status

Functional robotic arm successfully assembled and programmed to respond to control signals. System can be expanded in the future with additional degrees of freedom or sensor feedback.

## Author
Naafiul Hossain

## Date 
May 15 2022 
