g# User Stories

---

## **Exercise 0: Environment Setup and Initial Smoke Test**

### **User Story: Setting Up Development Environment**

**As a developer,**
I want to set up and verify my development environment,
**So that** I can ensure everything is configured correctly before starting development.

**Scenario:**

- **Given** a project setup with a defined environment,
- **When** I run the provided smoke test,
- **Then** I should see a successful result, confirming that the environment is ready for development.

---

### **User Story 1.1: Convert Celsius to Kelvin**

**As a developer,**
I want to make a conversion between Celsius to Kelvin,
**So that** I can ensure consistent handling of different data formats.

**Scenario:**

- **Given** a value in Celsius,
- **When** the conversion function is called,
- **Then** the function should return the value in Kelvin.

### **User Story 1.2: Convert Celsius Decigrades to Celsius**

**As a developer,**
I want to make a conversion between Celsius Decigrades to Celsius,
**So that** I can work with consistent, normalized data.

**Scenario:**

- **Given** a value in a Celsius Decigrades,
- **When** the conversion function is called,
- **Then** the Celsius value should be returned.

### **User Story 1.3: Convert Kelvin to Celsius**

**As a developer,**
I want to make a conversion between Kelvin to Celsius,
**So that** I can ensure consistent handling of different data formats.

**Scenario:**

- **Given** a value in Kelvin,
- **When** the conversion function is called,
- **Then** the function should return the value in Celsius.

---

## **Exercise 2: Testing Classes and Using Fixtures**

### **User Story 2.1: Initialize a Class with Default Values**

**As a developer,**
I want to ensure that a class initializes with default values,
**So that** I can confirm that it behaves predictably when first instantiated.

**Scenario:**

- **Given** a newly instantiated object,
- **When** it is initialized,
- **Then** all internal properties should have default values 0.

### User Story 2.2: Average temperature value

**As a Hardware Monitor,**
I want to have FilterData() method that calculates the correct average value of temperature,
**So that** I can do my monitoring properly.

**Scenario 1:**
- **Given** the Filter class has a buffer filled with the value 1 in all positions,
- **When** the FilterData() method is called,
- **Then** the returned average should be 1.

The test should be named `WhenApplyFilterWithDataAllSetToOnesThenReturnOneAsAverageValue`.
The test will initially fail, as the FilterData() method has not been implemented yet.

Test Setup:
- Use the PRIVATE macro to access the buffer in the Filter class.
- Ensure the buffer is initialized with the value 1 in all positions.


**Scenario 2:**
- **Given** a buffer in the Filter class filled with different values,
- **When** the FilterData() method is called,
- **Then** the method should accurately compute and return the average of the data in the buffer.


### **User Story 2.3: Update Temperature Buffer with New Values**

**As a Hardware Monitor,**
I want to have all the latest and greates temperature values,
**So that** I can monitor hardware appropriately.

**Scenario:**

- **Given** there is a hardware that is sensitive for temperature changes,
- **When** temperature changes,
- **Then** the average value changes accordingly.

---

## **Exercise 3: Introduction to GMock, Dependency Injection, and Mocks**

### **User Story 3.1: Make FilterData() Mockable**

**As a developer,**
I want to create a mock version of the Filter class (MockFilter),
**So that** I can create mock classes for unit testing without impacting production performance.

**Scenario:**

- **Given** the Filter class contains a FilterData() method,
- **When** the MOCK_ENABLE flag is defined during test builds,
- **Then** the FilterData() method should become virtual using MOCKABLE macro,
- **And** in production builds the method should remain non-virtual.

### **User Story 3.2: Create a Mock Version of Filter**

**As a developer,**
I want to build a mock implementation of the Filter class that overrides the FilterData() method,
**So that** I can simulate various filtering behaviors during tests.

**Scenario:**

- **Given** a base Filter class with a MOCKABLE FilterData() method,
- **When** I define a MockFilter using GoogleMock,
- **Then** I should be able to mock the FilterData() method’s behavior.

### **User Story 3.3: Validate ThermalSensor Interaction Using MockFilter**

**As a tester,**
I want to verify that the ThermalReader class interacts correctly with the Filter through a MockFilter,
**So that** I can ensure the system responds properly to varying filter outputs.

**Scenario 1: Successful Data Retrieval**

- **Given** a ThermalReader instance that depends on a Filter,
- **And Given** a MockFilter configured to return a fixed temperature value,
- **When** the ThermalReader invokes FilterData(),
- **Then** the expected temperature value should be used correctly in calculations.

**Scenario 2: Behavior Using Different Filter Outputs**

- **Given** MockFilter is configured to return different values across multiple calls,
- **When** ThermalReader reads temperature repeatedly,
- **Then** it should handle each returned value properly.

### **User Story 3.4: Validate ReadFilteredTemp() Behavior with MockFilter**

**As a tester,**
I want to verify the ReadFilteredTemp() method in the ThermalReader class using a MockFilter,
**So that** I can confirm that ThermalReader behaves correctly based on the mocked output from FilterData().

**Scenario:**

- **Given** a ThermalReader class that depends on a Filter for temperature readings,
- **And Given** a MockFilter is provided to ThermalReader through constructor injection,
- **When** ReadFilteredTemp() is invoked,
- **Then** it should return a temperature value that matches the mock behavior defined in FilterData().

---
