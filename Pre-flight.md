# Pre-Flight Checklist
---

## Assembly (Electrical)


#### Power Delivery Tray
- [ ] Check power and data connections
- [ ] Check battery voltages. They should be within approx 0.2V of each other. *Absolute minimum* voltage is 21V
- [ ] Attach battery alarms to each battery.
- [ ] Set each battery alarm to 3.5V by repeatedly pressing its button
- [ ] Insert batterys into power delivery tray and attach proper cables
- [ ] Insert power delivery tray into the rover.
- [ ] Ensure E-Stop is disabled (button is pressed)
- [ ] Plug E-stop into the power delivery tray


#### Controls Tray
- [ ] Check power and data connections. There should be no loose cables
- [ ] Insert controls tray *halfway* into the rover
- [ ] Plug in 3x RS-232 cables for arm stepper motors (color coded)
- [ ] Plug in 2x linear actuator cables (color coded)
- [ ] Plug in 3x left side motor cables (order agnostic)
- [ ] Plug in 3x right side motor cables (order agnostic)
- [ ] Attach antenna ethernet cable to POE adapter
- [ ] Attach GPS antenna to the GPS module
- [ ] Attach all relevent camera cables to usb hub (rover may be operated with missing cameras)
- [ ] Plug power delivery cable into the controls tray
- [ ] Push controls tray all the way into the rover

#### Base Station
- [ ] Plug POE adapter into wall outlet
- [ ] Plug base station into POE adapter with ethernet cable
- [ ] Plug laptop into base station with ethernet cable
- 


## Startup Procedure

- [ ] Twist and then pull the E-stop button to enable the rover
- [ ] Check that the rover is powered on by looking at the power delivery tray. There should be a lot of blinking lights
- [ ] Wait for the rover to boot up. This usually takes about 1-2 minutes.
- [ ] From a remote computer, ssh into the rover with `ssh robotics@uirover.local` (if this doesnt work try `ssh robotics@192.168.1.37`)
- [ ] If prompted for a password, enter `rover123`
- [ ] Check if the docker container is running with `docker ps`. You should see a container named `uirover`
- [ ] If the container is not running, start it with `./Rover/docker/start-detached.sh`