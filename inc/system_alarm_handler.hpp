#pragma once
#include <iostream>
using namespace std;

class SystemAlarmHandler
{
public:
     ~SystemAlarmHandler();
     string ReportOverheating();
     string ReportUnderheating();
};