#include "VendingMachine.h"

VendingMachine::VendingMachine() : stateMachine(), productManagement(), inventoryManagement() {}  // Constructor definition initializing state machine, product management, and inventory management

ProductManagement& VendingMachine::getProductManagement() {
    return productManagement;  // Return the product management
}

InventoryManagement& VendingMachine::getInventoryManagement() {
    return inventoryManagement;  // Return the inventory management
}

void VendingMachine::start() {
    stateMachine.transitionTo(State::Idle);  // Start the vending machine in the idle state
}

StateMachine& VendingMachine::getStateMachine() {
    return stateMachine;  // Return the state machine
}
