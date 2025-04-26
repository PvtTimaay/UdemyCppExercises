#include "AcStateMachine.h"

AcStateMachine::AcStateMachine(AirConditioner* ac)
    : ac(ac), state(AcStates::IDLE)
{
}

void AcStateMachine::eval_transition(int temp) {
    switch (state) {
        case AcStates::IDLE:
            if (temp > 25) {
                state = AcStates::COOLING;
            } else if (temp < 18) {
                state = AcStates::HEATING;
            }
            break;
        case AcStates::COOLING:
            if (temp <= 22) {
                state = AcStates::IDLE;
            } else if (temp < 18) {
                state = AcStates::HEATING;
            }
            break;
        case AcStates::HEATING:
            if (temp >= 22) {
                state = AcStates::IDLE;
            } else if (temp > 25) {
                state = AcStates::COOLING;
            }
            break;
    }
}

void AcStateMachine::eval_state(int temp) {
    switch (state) {
        case AcStates::IDLE:
            std::cout << "AC is IDLE\n";
            break;
        case AcStates::COOLING:
        case AcStates::HEATING:
            if (ac) {
                ac->activate(static_cast<float>(temp));
            }
            break;
    }
}

void AcStateMachine::evaluation(int temp) {
    eval_transition(temp);
    eval_state(temp);
}

AcStates AcStateMachine::get_state() const {
    return state;
}
