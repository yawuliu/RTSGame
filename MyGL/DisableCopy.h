#pragma once

class DisableCopy {
public:
    
    DisableCopy() = default;

    
    DisableCopy(const DisableCopy &) = delete;

    
    DisableCopy &operator=(const DisableCopy &) = delete;

    
};



