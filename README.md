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

## Options
### Power modes
The MCP9808 offers a continuous conversion mode or a low-power mode where the sensor only draw 0.1µA.
The low power mode is also called shutdown mode. Continuous conversion is the default mode.
You can select either with setPowerMode :
```C++
    mcp.setPowerMode(MCP9808_CONTINUOUS);
```
or
```C++
    mcp.setPowerMode(MCP9808_LOW_POWER);
```

### Resolution and Speed modes
If you want to get more frequent temperature readings you'll need to lower the resolution.
The best resolution is +/-0.0625°C resolution	and takes 250ms of conversion time : MCP9808_SLOWEST
The fastest conversion time is 30ms and has a resolution of +/- 0.5°C : MCP9808_FASTEST
MCP9808_SLOWEST / MCP9808_SLOW / MCP9808_FAST / MCP9808_FASTEST

```C++
    mcp.setResolution(MCP9808_SLOWEST);
```

## Contributing

1. Fork it (https://github.com/romainmp/MCP9808/fork)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
