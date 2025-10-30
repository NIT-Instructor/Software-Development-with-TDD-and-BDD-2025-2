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


### **User Story 5.1: Separate Acceptance Tests from Unit Tests**

**As a developer**,
I want to organize acceptance tests in a separate directory with their own build configuration,
**So that** the project structure remains clean, modular, and easy to maintain.

**Scenario 1: Create a dedicated directory for acceptance tests**
- **Given** a project that already contains unit tests in the /tests directory
- **When** I create a new /acceptance directory
- **Then** the /acceptance directory should contain all acceptance test source files and related configurations
- **And** acceptance test files should not be mixed with unit test files.


**Scenario 2: Include necessary libraries and dependencies**

**Given** the acceptance tests rely on external dependencies
**When** the acceptance build is set up
**Then** it should link against the raw_temp C library and any other required dependencies
**And** ensure that the build passes without unresolved symbols.

### **User Story 5.2: Use Real Implementations in Acceptance Tests**

**As a developer**,
I want to run acceptance tests using real implementations of all system components,
**So that** I can validate that the integrated system behaves correctly under realistic conditions.

**Scenario: Execute acceptance tests with real implementations**
**Given** the acceptance test environment is configured with real classes (Filter, ThermalReader, and RawTempFacade)
**When** the acceptance tests are executed
**Then** the system should read raw temperature data via the real RawTempFacade
**And** process it through the actual ThermalReader and Filter components
**And** produce filtered temperature results that reflect the expected real-world data flow without using mocks.

### **User Story 5.3: Run parameterized tests using real temperature data to validate thermal filtering logic**

**As a developer**,
I want to use parameterized acceptance tests with real C library input
**So that** I can validate the thermal filtering logic under multiple conditions and ensure realistic, reliable results

**Scenario 1: Run parameterized tests with different update counts**
**Given** a set of test parameters including numOfUpdates and expectedFilteredValue
**And**   a test fixture class inheriting from ::testing::TestWithParam<ParamStruct>
**When**  I run the parameterized test using the TEST_P macro
**Then**  UpdateCurrentTemp() is called the specified number of times
**And**   the filtered temperature is retrieved
**And**   the result matches the expected filtered value for each parameter set.

**Scenario 2: Execute tests using real C library temperature loop**

**Given**  the test is linked to the real C library
**And**    the library returns temperatures from 0 to 120 cyclically
**When**   UpdateCurrentTemp() is invoked in a loop across multiple test cases
**Then**   realistic temperature data flows into the system
**And**    the thermal filtering logic handles edge cases, including wrap-around behavior

**Scenario 3: Efficiency and clarity of tests**

**Given** parameterized tests are implemented
**When**  I add new test cases
**Then**  I can do so without duplicating test logic
**And**   the test scenarios remain readable and maintainable


### **Project - User Story 1: Hardware Monitor Temperature and Report Alarms**
 
**As a developer**,
I want the HardwareMonitor to continuously track and filter temperature readings
**So that** the system always has up-to-date and smoothed temperature values.
 
**Scenario 1: Regular Temperature Update and Filtering**
**Given** the HardwareMonitor is active
**And** a valid temperature sensor is providing readings
**When** the HardwareMonitor samples the temperature every 100ms
**And** updates the temperature filter with the new value
**Then** the filtered temperature value should reflect the latest readings
**And** the filter should smooth out transient spikes or noise.

**Scenario 2: Update Not Called**

**Given** the HardwareMonitor is active
**When** no update is called
**Then** the filter remains unchanged

**Scenario 3: Update Called Faster Than 100ms**

**Given** the HardwareMonitor is active
**When** updates are called faster than 100ms
**Then** the filter should not be updated too often

**Scenario 4: Update Called Slower Than 100ms**

**Given** the HardwareMonitor is active
**When** updates are called slower than 100ms
**Then** the filter should be updated on each call

### **Project - User Story 2: Configure and Validate Temperature Thresholds**

**As a developer**,

I want to define minimum and maximum temperature thresholds
**So that** the monitoring system can trigger alarms when limits are exceeded

**Scenario 1: Return current thresholds**

**Given** the system is initialized
**When**  the thresholds are requested
**Then**  the coding module returns the current minimum and maximum temperature values

**Scenario 2: Accept thresholds within limits**

**Given**  predefined acceptable threshold limits
**When**   a new minimum and maximum are set within these limits
**Then**   the values are accepted and saved

**Scenario 3: Reject thresholds outside limits**

**Given**  predefined acceptable threshold limits
**When**   a value is set that falls outside the allowed range
**Then**   the coding module rejects it and reports an error
