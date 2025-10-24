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

### **User Story 3.1: Implement MockFilter for ThermalReader Testing**

**As a developer writing tests for ThermalReader,**  
I want to create a mock version of the Filter class (MockFilter),
**So that** I can simulate and control FilterData() behavior for testing ThermalReader without relying on real filtering logic.

**Scenario:**

- **Given** that the Filter class contains a FilterData() method,
- **And** the MOCKABLE macro is applied to make it virtual when MOCK_ENABLE is defined,
- **When** the code is compiled with MOCK_ENABLE defined,
- **Then** the FilterData() method should be virtual,
- **And** test code should be able to override it using GoogleMock.


### **User Story 3.2: Apply GoogleMock for Controlled Testing**

**As a developer running tests for ThermalReader,**  
I want to use GoogleMock to expect and verify a single call to FilterData(),
**So that** I can ensure ReadFilteredTemperature() interacts with dependencies exactly once as intended.

**Scenario1: Expect single call to FilterData**

- **Given** a MockFilter instance is created
- **And** it is passed to ThermalReader upon initialization
- **And** EXPECT_CALL(mockFilter, FilterData()).Times(1) is set with WillOnce(Return(V))
- **When** ReadFilteredTemperature() is invoked
- **Then** it should call FilterData() exactly once
- **And** return the value V as defined in WillOnce


### **User Story 3.3: Validate ReadFilteredTemp() with Multiple and Repeated Returns**

**As a developer validating multiple outcomes from ReadFilteredTemperature()**,
I want to configure MockFilter to return different values on successive and repeated calls,
**So that** I can confirm that ThermalReader handles dynamic mock responses correctly.

**Scenario 1: Return distinct values on multiple calls**
- **Given** a MockFilter instance is injected into ThermalReader
- **And** EXPECT_CALL(mockFilter, FilterData()) is set with WillOnce(Return(X)) followed by WillOnce(Return(Y))
- **When** ReadFilteredTemperature() is called twice
- **Then** the first call should return X
- **And** the second call should return Y


**Scenario 2: Use WillRepeatedly for fallback behavior**
- **Given** a MockFilter is configured with EXPECT_CALL(mockFilter, FilterData()).WillOnce(Return(X)).WillOnce(Return(Y)).WillRepeatedly(Return(Z))
- **When** ReadFilteredTemperature() is called more than twice
- **Then** the third and all subsequent calls should return Z 


---
