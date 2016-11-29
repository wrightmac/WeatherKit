# WeatherKit
// Files for my Arduino Uno Weather Kit

This project is for a basic, Arduino based, weather monitoring station. While this project is for indoor use only, one could easily find an appropriate weather proof case; and using battiers or solar power with wireless place it outside. This kit is meant as an introduction to the Arduino platform, using sensors, and a door to a fun world. 
<P>
<B><I>Parts needed:</I></B>
<P>
1 x Arduino Uno clone<BR>
1 x 25cm micro USB data cable<BR>
1 x DHT22 sensor<BR>
1 x BMP280 sensor<BR>
1 x 5110 84x48 LCD screen<BR>
xx x Male to Female Jumper Cables<BR>
xx xx Female to female Jumper Cables<BR>
2 x 10k resistors - for sensors<BR>
1 x 470Ohm resistor - for LCD<BR>
<P>
<H2><I>Let's get started!</I></H2>
<P>

Fritzig drawing - need to rotate Uno board and "rewire"
	upload to here
<P>	
<B>Wiring for the LCD</B>
<P>
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{font-family:Arial, sans-serif;font-size:14px;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg th{font-family:Arial, sans-serif;font-size:14px;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg .tg-s6z2{text-align:center}
.tg .tg-baqh{text-align:center;vertical-align:top}
.tg .tg-e3zv{font-weight:bold}
.tg .tg-hgcj{font-weight:bold;text-align:center}
.tg .tg-yw4l{vertical-align:top}
</style>
<table class="tg">
  <tr>
    <th class="tg-e3zv">LCD Pin</th>
    <th class="tg-hgcj">Arduino Pin</th>
  </tr>
  <tr>
    <td class="tg-031e">1 - RST</td>
    <td class="tg-s6z2">12</td>
  </tr>
  <tr>
    <td class="tg-031e">2 - CE</td>
    <td class="tg-s6z2">11</td>
  </tr>
  <tr>
    <td class="tg-031e">3 - DC</td>
    <td class="tg-s6z2">10</td>
  </tr>
  <tr>
    <td class="tg-031e">4 - Dir</td>
    <td class="tg-s6z2">9</td>
  </tr>
  <tr>
    <td class="tg-031e">5 -Clk</td>
    <td class="tg-s6z2">8</td>
  </tr>
  <tr>
    <td class="tg-yw4l">6 - Vcc</td>
    <td class="tg-baqh">3.3v</td>
  </tr>
  <tr>
    <td class="tg-yw4l">7 - BL</td>
    <td class="tg-baqh">7 - with 470Ohm resistor</td>
  </tr>
  <tr>
    <td class="tg-yw4l">8 - GND</td>
    <td class="tg-baqh">Ground</td>
  </tr>
</table>
<P>		
The LCD is based on the old Nokia 5110 LCD screen used in their phones. It is a decent sreen and easy to find. It is 84x48 pixels. This model uses SPI for its communication with the Arduino. There are other ones out there that use the I2C protocol which only requires 4 pins. There are some different libraries out there. I used xxx in this project. The basic functions are well-documented and they also have an additional library with graphical functions in it as well. Keeping some historical data and being able to graph them over time is a good additional project. One could store the data on an SD card or rely it via wireless. There is a section of code that shows how to output data in a CVS format for later analysis. The library is located here. 
		
<P>
<B>Wiring for the DHT22</B>
<P>	
	DHT22 Pin	Arduino Pin
	1		5v
	2		2 (plus add 10k resistor to power)
	3		Open, not used
	4		Ground
The DHT22 is a low-cost, but accurate, digital temperature and humidity sensor. It has a captive humidity sensor and a thermistor for reading the ambient temperature. It is 3-5v tolerant for both the Vcc (power in) and digital signal line (pin 2). The pins are 1 -4, left to right, looking at the front (the grill side).

<P>
<B>Wiring for the BMP280</B>
<P>
BMP820 Pin		Arduino Pin
Vcc			3.3v
GND			Ground
SCL			A5
SDA			A4
CSB			Open, not used
SD0			Pull high with power with xx resistor for address 0x76
			pull low with ground xx resistor for address 0x77
<P>

