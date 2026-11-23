Thermostat::Thermostat(int degrees) : degrees_(degrees) {
    if (degrees_ < 16) {
        degrees_ = 16;
    }
    if (degrees_ > 30) {
        degrees_ = 30;
    }
}

void Thermostat::warmer() {
    if (degrees_ < 30) {
        ++degrees_;
    }
}

void cooler() {
    if (degrees_ > 16) {
        --degrees_;
    }
}

int Thermostat::degrees() {
    return degrees_;
}
