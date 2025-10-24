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

### **User Story 4.1: Create External C Library for Temperature Simulation**

**As a developer**,
I want a simulated C library that mimics reading a temperature sensor,
So that I can test system behavior without hardware dependency

**Scenario 1:**

- **Given** the C library is initialized,  
- **When**  the application is in a test environment,  
- **Then**  it should use the C mock library that mimics reading a sensor and returns a progression of temperature value.


### **User Story 4.2: Introduce Adapter for Raw Temperature Reading**

**As a developer**,
I want to isolate hardware access through a RawTempFacade adapter,
So that I can mock temperature readings during tests.

**Scenario 1:**
- **Given** a mock RawTempFacade returning 42,
- **When**  UpdateCurrentTemp() is invoked,
- **Then**  Filter::UpdateFilterData() should be called with 42.

**Scenario 2:**
- **Given** a test context,
- **When**  a mock RawTempFacade is injected into ThermalReader,
- **Then**  the real C library is not called.


---
