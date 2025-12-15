# IOT-Project

Implementation of an IoT system that monitors how busy a room is using three wireless technologies.
A “Lighthouse” device scans with BLE and Wi-Fi its surroundings, estimates the crowd level, and sends a compact status
message to The Things Network (TTN) using LoRaWAN. A dashboard then visualizes the current and
historical room status. This gives an up-to-date visual indicator of how busy the monitored room is.
The Lighthouse Node can also track a specific device using BLE. 
