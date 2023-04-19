# water level sensor
water level sensor 즉, 수분 수위 센서는 센서에 물이 닿으면 상대적으로 전류가 잘흐르게 된다. 하여 저항 값이 내려가게 된다. 이를 통해 물의 수위를 측정할 수 있는 센서이다.

## Hardware Structure

---
`+` : 5V

`-` : GND

`S` : analog PIN

```
int water_sensor = A3;

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    int sersor_data = analogRead(water_sensor);
    Serial.println(sersor_data);
}

```
