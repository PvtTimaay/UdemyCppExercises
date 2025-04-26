#pragma once

#include "AirConditioner.h"

enum class AcStates {
    IDLE,
    COOLING,
    HEATING
};

class AcStateMachine {
private:
    AirConditioner* ac;
    AcStates state;

    void eval_transition(int temp);
    void eval_state(int temp);

public:
    AcStateMachine(AirConditioner* ac);
    void evaluation(int temp);
    AcStates get_state() const;
};
