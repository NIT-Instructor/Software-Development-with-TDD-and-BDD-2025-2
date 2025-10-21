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

Exercise 3: Testing Classes and Using Fixtures

## **Exercise 3: Introduction to GMock, Dependency Injection, and Mocks**

### User Story 3.1: ThermalReader Provides Accurate and Stable Temperature Data to the Hardware Monitor

**As a Hardware Monitor,**
I want to have all the latest and greatest temperature values,
**So that** can monitor hardware appropriately and respond to environmental changes in real time.

**Scenario 1:** ThermalReader updates average temperature when sensor values change

- **Given** there is hardware that is sensitive to temperature fluctuations
- **And** the ThermalReader continuously reads raw temperature values
- **When** the temperature changes from one reading to another
- **Then** the Filter should calculate a new average temperature
- **And** the ThermalReader should provide the updated average to the Hardware Monitor

**Scenario 2:** ThermalReader applies filtering to stabilize temperature readings

- **Given** the hardware requires stable readings to avoid reacting to noise
- **And** ThermalReader passes raw sensor values through a Filter
- **When** rapid fluctuations occur in the input readings (e.g., [60.0, 61.5, 59.0, 60.8])
- **Then** the resulting average temperature should change gradually
- **And** the Hardware Monitor should receive a smooth, stable temperature trend

**Scenario 3:** ThermalReader ensures latest temperature is always available

- **Given** the system collects temperatures periodically
- **When** the Hardware Monitor requests the current temperature
- **Then** ThermalReader should return the most recent filtered value
- **And** ensure no outdated or stale data is provided

