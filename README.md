# MCP9808
A Library to add support of MCP9808 precision temperature sensor to Particle core (Formerly Spark Core).

## Usage
Before your setup function
```C++
#include "MCP9808/MCP9808.h"
MCP9808 mcp = MCP9808();
```

In your setup function
```C++
    // MCP9808 sensor setup
    while(! mcp.begin()){
        Serial.println("Couldnt find MCP9808");
        delay(1000);
    }
    mcp.setResolution(MCP9808_SLOWEST);
```
In your loop you can now get the temperature like that
```C++
    temperature = mcp.getTemperature();
```

## Contributing

1. Fork it (https://github.com/romainmp/MCP9808/fork)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
