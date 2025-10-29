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

## **Project: Hardware Monitor**

### **User Story 6.1: [Project] Implement Blank Hardware Monitor**

**As a developer**
I want to create a blank HardwareMonitor class with structure and interfaces only,
**So that** I can later extend it to handle temperature updates, filtering, and alarm logic.

**Scenario:** 
Initialize basic HardwareMonitor

- **Given** a new HardwareMonitor class without any logic implemented,
- **When** the object is instantiated,
- **Then** it should compile successfully and provide placeholders for:

  - Updating temperature every 100 ms
  - Reading filtered temperature
  - Comparing temperature against thresholds
  - Interacting with Codings and SystemAlarmHandler

**Acceptance Criteria:**

- The HardwareMonitor class compiles and can be instantiated.
- No functional behavior (e.g., filtering or alarm) is yet implemented.
- Public methods like UpdateTemperature(), ReadFilteredTemperature(), and CheckAlarms() are declared but return placeholder values.

### **User Story 6.2: [Project] Implement Codings**

**As a developer,**
I want to define temperature thresholds and validate their plausibility,
**So that** other modules can use consistent and valid limits for system monitoring.

**Scenario 1:** 
Provide threshold values

- **Given** a new Codings class,
- **When** the class is instantiated,
- **Then** it should expose GetMinTemperatureThreshold() and GetMaxTemperatureThreshold() methods returning default values.

**Scenario 2:**
Validate thresholds

- Given an invalid configuration where thresholds exceed the defined safe limits,
- When CheckThresholdPlausibility() is called,
- Then it should return false.

**Scenario 3:**
Valid configuration

- Given thresholds within acceptable predefined limits,
- When CheckThresholdPlausibility() is called,
- Then it should return true.

**Acceptance Criteria:**

- Unit tests validate threshold retrieval and plausibility checking.
- The module is self-contained and testable.
- Tests include both valid and invalid threshold scenarios.


### **User Story 6.3: [Project] Implement SystemAlarmHandler**

**As a developer,**
I want to detect and report overheating or underheating events,
**So that** the system can react appropriately to temperature anomalies.

**Scenario 1:**
Report overheating alarm

- **Given** a filtered temperature higher than the maximum threshold,
- **When** ReportOverheating() is invoked,
- **Then** it should log “Overheating detected!” to the console.

**Scenario 2:**
Report underheating alarm

- **Given** a filtered temperature lower than the minimum threshold,
- **When** ReportUnderheating() is invoked,
- **Then** it should log “Underheating detected!” to the console.

**Scenario 3:**
Logging verification

- **Given** multiple alarms are triggered sequentially,
- **When** the alarms are reported,
- **Then** each message should be logged distinctly in the console.

**Acceptance Criteria:**

- SystemAlarmHandler has methods ReportOverheating() and ReportUnderheating().
- Console output matches expected log messages.
- Mockable logging for test verification.


### **User Story 6.4: [Project] Integrate HardwareMonitor, Codings, and SystemAlarmHandler**

**As a system integrator,**
I want to connect HardwareMonitor, Codings, and SystemAlarmHandler together,
**So that** the system continuously monitors temperature and reacts to alarm conditions.

**Scenario 1:**
Normal operation

- **Given** temperature values within thresholds,
- **When** the monitor updates every 100 ms,
- **Then** no alarm is reported.

**Scenario 2:**
Overheating detection

- **Given** the filtered temperature exceeds the maximum threshold,
- **When** HardwareMonitor compares the temperature,
- **Then** it should invoke SystemAlarmHandler::ReportOverheating().

**Scenario 3:**
Underheating detection

- **Given** the filtered temperature drops below the minimum threshold,
- **When** HardwareMonitor compares the temperature,
- **Then** it should invoke SystemAlarmHandler::ReportUnderheating().

**Scenario 4:**
Plausibility check failure

- **Given** Codings detects implausible thresholds,
- **When** HardwareMonitor performs an update,
- **Then** it should skip alarm evaluation and log a plausibility warning.

**Acceptance Criteria:**

- Integrated unit tests confirm module interaction via mocks.
- HardwareMonitor depends on injected Codings and SystemAlarmHandler.
- Behavior is verified via TDD acceptance and integration tests.