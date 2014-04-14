

# Items
```
String ArdVal_Garden_A0 "Raw value A0: [%s]" <temperature> (Garden) 
String ArdVal_Garden_A1 "Raw value A1: [%s]" <temperature> (Garden) 
String ArdVal_Garden_A2 "Raw value A2: [%s]" <temperature> (Garden) 


Number Temp_Garden_Soil "Soil [%.1f]" <temperature> (Garden) 
```


# Rules

```
import java.lang.Double
import java.lang.String


var Number ArdVal_Garden_A1_converted
var Double ArdVal_Garden_A1_adc = 0.0f



rule "ArdVal_Garden_A1 conversion"
when
    Item ArdVal_Garden_A1 changed
then
    ArdVal_Garden_A1_adc = Double::valueOf(ArdVal_Garden_A1.state.toString)
    ArdVal_Garden_A1_adc = ArdVal_Garden_A1_adc * (5.0/1023.0) * 125/3.0 - 40
    Temp_Garden_Soil.postUpdate(ArdVal_Garden_A1_adc)    
end
```

# debug

```
http://192.168.2.201:8080/rest/items/ArdVal_Garden_A1
http://192.168.2.201:8080/rest/items/Temp_Garden_Soil
```