#include "MedicineRecordChild.h"

MedicineRecordChild::MedicineRecordChild(const char* name, int day) : MedicineRecord(name, day) {}

MedicineRecordChild::MedicineRecordChild(const MedicineRecord& other, bool copyPlan) : MedicineRecord(other, copyPlan) {}

MedicineRecordChild::MedicineRecordChild(const char* name, int day, const char* explanation) : MedicineRecord(name, day)
{
    if (explanation != nullptr && strlen(explanation) > 0)
    {
        this->explanation = new char[strlen(explanation) + 1];
        strncpy_s(this->explanation, strlen(explanation) + 1, explanation, _TRUNCATE);
    }
    else
    {
        throw invalid_argument("Ошибка");
    }
}

void MedicineRecordChild::setExplanation(const char* explanation) 
{
    if (explanation != nullptr && strlen(explanation) > 0) 
    {
        this->explanation = new char[strlen(explanation) + 1];
        strncpy_s(this->explanation, strlen(explanation) + 1, explanation, _TRUNCATE);
    }
    else
    {
        throw invalid_argument("Ошибка");
    }
}

const char* MedicineRecordChild::getExplanation() const 
{
    return explanation;
}

void MedicineRecordChild::printMedicineInfo() const
{
    MedicineRecord::printMedicineInfo();
    if (explanation != nullptr) 
    {
        cout << "Дополнительное пояснение: " << explanation << endl;
    }
}
