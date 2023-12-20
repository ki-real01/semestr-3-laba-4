#pragma once
#include "MedicineRecord.h"

class MedicineRecordChild : public MedicineRecord 
{
public:
    MedicineRecordChild(const char* name, int day);
    MedicineRecordChild(const char* name, int day, const char* explanation);
    MedicineRecordChild(const MedicineRecord& other, bool copyPlan);

    void setExplanation(const char* explanation);
    const char* getExplanation() const;
    void printMedicineInfo() const;
private:
    char* explanation = nullptr;
};