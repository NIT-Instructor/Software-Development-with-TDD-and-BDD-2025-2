#pragma once

class Codings {
public:

    Codings();

    float GetMinThreshold() const;
    float GetMaxThreshold() const;

    bool CheckThresholds(float) const;

    void SetMinThreshold(float);
    void SetMaxThreshold(float);

private:
    float min_threshold_;
    float max_threshold_;
};
