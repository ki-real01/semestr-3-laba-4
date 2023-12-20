#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept> 

using namespace std;

class MedicineRecord {
public:
    enum TimeOfDay { MORNING, MIDDAY, DAY, AFTERNOON, NIGHT };
    MedicineRecord(const char* name, int day);
    MedicineRecord(const MedicineRecord& other, bool copyPlan);
    ~MedicineRecord();
private:
    TimeOfDay TimeofDay;
public:
    static const int CntPlans = 5;
    const char* getMedicineName() const;
    int getDay() const;
    void printMedicineInfo() const;
    void setPlan(TimeOfDay timeOfDay);
    void takeMedicine(TimeOfDay timeOfDay);
    bool planMatchesActual() const;

    void operator[](TimeOfDay timeOfDay);
    bool takeMedicineAt(TimeOfDay timeOfDay) const;
    friend ostream& operator<<(ostream& out, const MedicineRecord& record);
protected:
    char* medicineName = nullptr;
    int day = 0;
    int dosagePerDay = 0;
    bool plan[CntPlans];
    bool actual[CntPlans];
};
