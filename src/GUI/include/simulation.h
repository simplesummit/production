#ifndef SIMULATION_H
#define SIMULATION_H

#include <QDebug>
#include <QFile>

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <unistd.h>

/*! \class Simulation
 *  \brief The abstract class that underlies the Smoke and Fluid simulations.
 *
 *  It applies the prebuilt UI, reads joystick input, and creates animations.
 */
class Simulation {
public:
    virtual void StartSim() = 0; /*!< Starts the simulation */
    virtual void EndSim() = 0; /*!< Ends the simulation */

    bool SimIsActive() {return isActive;} /*!< Checks simulation status */

    /** Grab results of bash command.
     * \param cmd Command to grab output from.
     *
     * Runs the command, reads the string, and converts it to 
     * an unsigned int to be used as a Window ID. (See Simulation 
     * page for more)
     */
    unsigned int GetStdoutFromCommand(std::string cmd) {
        std::string data;
        unsigned int result;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        
        cmd.append(" 2>&1");
        stream = popen(cmd.c_str(), "r");
        if(stream) {
            while(!feof(stream))
                if(fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
            pclose(stream);
        }
        std::stringstream ss;
        ss << std::hex << data;
        ss >> result;
       
        return result;
    }
    float update_cpu() {
        float test = 0.00;
        QFile file("/sys/devices/virtual/thermal/thermal_zone1/temp");
        file.open(QFile::ReadOnly);
        QString times = file.readLine();
        int totalTime = times.split("\n")[0].toInt();
        test = (totalTime / 1000);
        if(test != 0.00) {
            return test;
        }
        throw "Invalid CPU Temperature Value";
        return -1;
    }

    float update_gpu() {
        float test = 0.00;
        QFile file("/sys/devices/virtual/thermal/thermal_zone2/temp");
        file.open(QFile::ReadOnly);
        QString times = file.readLine();
        int totalTime = times.split("\n")[0].toInt();
        test = (totalTime / 1000);
        if(test != 0.00) {
            return test;
        }
        throw "Invalid GPU Temperature Value";
        return -1;
    }
private:
    bool isActive; //!< Simulation status
};
#endif // SIMULATION_H
