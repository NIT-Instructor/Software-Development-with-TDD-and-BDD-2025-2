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

## **User Story 5.1: Set Up the Project Structure for Acceptance Tests**

**As a developer,**  
I want to keep acceptance tests in a separate directory,  
**So that** the project remains clean and well-structured.

### **Scenario**

- **Given** a new `/acceptance` directory,
- **When** I configure the build system,
- **Then** it should link real implementations (Filter, ThermalReader, raw_temp),


## **User Story 5.2: Use Real Implementations in Acceptance Tests**

**As a developer,**
I want acceptance tests to use real implementations instead of mocks,
**So that** I can verify the system’s actual behavior in realistic conditions.

### **Scenario**

- **Given** the acceptance test environment,
- **When** I instantiate real classes (`Filter`, `ThermalReader`, and `RawTempFacade`),
- **Then** the tests should execute the full data flow from reading raw temperatures to filtering results,
- **And** confirm that all components work together correctly without using mocks (like `MOCK_ENABLE=0`).


## **User Story 5.3: Write Parameterized Acceptance Tests**

**As a developer,**
I want to write parameterized acceptance tests using `TEST_P`,
**So that** I can validate different scenarios efficiently without duplicating code.

### **Scenario**

- **Given** a parameter structure with fields like `numOfUpdates` and `expectedFilteredValue`,
- **When** the test runs with different parameter sets (e.g., `{2, 10}` or `{3, 20}`),
- **Then** it should call `UpdateCurrentTemp()` the specified number of times,
- **And** verify that the resulting filtered temperature matches the expected value,
- **Ensuring** that all test cases share the same logic but different inputs and outcomes even when the temperature resets to 0.

---

## **Project: Hardware Monitor**

### **User Story Project: Hardware Monitor - Implement Codings by Following TDD & BDD Methodologies**

**As a developer,**
I want the `Coding` class to define and provide access to minimum and maximum temperature limits and predefined range check,
**So that** the Hardware Monitor can evaluate accurate temperature comparisons and validations.

#### **Scenario 1: Retrieve Minimum Threshold**
- **When** the Hardware Monitor requests the minimum temperature limit,
- **Then** the `Coding` class should return the configured minimum threshold.

**Scenario 2: Retrieve Maximum Threshold**
- **When** the Hardware Monitor requests the maximum temperature limit,
- **Then** the `Coding` class should return the configured maximum threshold.

#### **Scenario 3: Validate Temperature Within Range**
- **When** the Hardware Monitor checks if the current temperature is within limits,
- **Then** the `Coding` class should correctly determine and return whether it is inside or outside the range.


### **User Story Project: Hardware Monitor - Implement SystemAlarmHandler by Following TDD & BDD Methodologies**

**As a developer,**  
I want to implement a `SystemAlarmHandler` to log overheating and underheating alarms,  
**So that** users can be notified when the system temperature goes beyond safe operating limits.

#### **Scenario 1: Overheating Condition**

- **When** `ReportOverheatingAlarm` is called,  
- **Then** the system logs a message indicating that the temperature value is too high.

#### **Scenario 2: Underheating Condition**

- **When** `ReportUnderheatingAlarm` is called,  
- **Then** the system logs a message indicating that the temperature value is too low.


### **User Story Project: Hardware Monitor - Implement HardwareMonitor by Following TDD & BDD Methodologies**

**As a developer,**
I want the Hardware Monitor to continuously observe and validate temperature readings,
**So that** it can trigger and record alarms when specific conditions occur.

#### **Scenario 1 – Updating Temperature Filter**
- **When** a new temperature measurement arrives every 100ms,
- **Then** the Hardware Monitor should update the filter with new value.

#### **Scenario 2 – Comparing Temperature to Thresholds**
- **When** the Hardware Monitor retrieves the filtered temperature,
- **Then** it checks whether the value is within the minimum and maximum thresholds defined by the Codings class.

#### **Scenario 3 – Validating Threshold Codings**
- **When** the Hardware Monitor handles incoming temperature data,
- **Then** it verifies that the provided coding for the thresholds is plausible.

#### **Scenario 4 – Handling Overheating Condition**
- **When** the filtered temperature exceeds the maximum allowed limit,
- **Then** the Hardware Monitor reports an overheating alert to the System Alarm Handler.

#### **Scenario 5 – Handling Underheating Condition**
- **When** the filtered temperature falls below the minimum limit,
- **Then** the Hardware Monitor raises an underheating alert to the System Alarm Handler.

---