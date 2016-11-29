# Arduino Basic Indoor Weather Station

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
<B><I>Software needed:</I></B>
<P>
Arduino IDE 1.6.x
Various Libraries, find links in the docs. 
<P>
<H2><I>Let's get started!</I></H2>
<P>
The order of the parts listed below are the order I wired up and tested each part. It makes trouble shooting easier to take each component, wire it up, install the library, load a test sketch, and make sure it works. Nothing is more frustrating than plugging in 14 wires and nothing happening. 
<P>
Be sure and check your connections. I will admit to pulling an oops and damaging a component by not paying attention to where those pesky Vcc and ground wires were going. If you have issues, check your wiring first. If you have a multimeter, you can also make sure you have continuity and expected voltages. 
<P>
Fritzig drawing - need to rotate Uno board and "rewire"
	upload to here
<P>	

		
<P>
<H2>The DHT22</H2>
<P>	
<table class="tg">
  <tr>
    <th class="tg-e3zv">DHT22 Pins</th>
    <th class="tg-hgcj">Arduino Pins</th>
  </tr>
  <tr>
    <td class="tg-031e">1 - Vcc</td>
    <td class="tg-s6z2">5v</td>
  </tr>
  <tr>
    <td class="tg-031e">2 - Signal + 10k</td>
    <td class="tg-s6z2">2</td>
  </tr>
  <tr>
    <td class="tg-031e">3 - Open</td>
    <td class="tg-s6z2">Open</td>
  </tr>
  <tr>
    <td class="tg-031e">4 - Gnd</td>
    <td class="tg-s6z2">Ground</td>
  </tr>
</table>
The DHT22 is a low-cost, but accurate, digital temperature and humidity sensor. It has a captive humidity sensor and a thermistor for reading the ambient temperature. It is 3-6v tolerant for both the Vcc (power in) and digital signal line (pin 2). The pins are 1 -4, left to right, looking at the front (the grill side).
<P>
Arduino pin 2 is used in this sketch, but any other pin could be used. 
<P>
Here is a link to the <A HREF="http://www.electroschematics.com/wp-content/uploads/2015/02/DHT22-datasheet.pdf">DHT22 datasheet.</A>
<P>

<P>
<H2>The BMP280</H2>
<P>
<table class="tg">
  <tr>
    <th class="tg-e3zv">BMP280 Pins</th>
    <th class="tg-e3zv">Arduino Pins</th>
  </tr>
  <tr>
    <td class="tg-031e">Vcc</td>
    <td class="tg-031e">5v</td>
  </tr>
  <tr>
    <td class="tg-031e">Gnd</td>
    <td class="tg-031e">Ground</td>
  </tr>
  <tr>
    <td class="tg-031e">SCL</td>
    <td class="tg-031e">A5</td>
  </tr>
  <tr>
    <td class="tg-031e">SDA</td>
    <td class="tg-031e">A4</td>
  </tr>
  <tr>
    <td class="tg-yw4l">CSB</td>
    <td class="tg-yw4l">Open</td>
  </tr>
  <tr>
    <td class="tg-yw4l">SD0</td>
    <td class="tg-yw4l">High - 0x76<br>Low - 0x77</td>
  </tr>
</table>
<P>
The BMP280 is a barometric pressure and temperature sensor. It is a sensor with great accuracy. In fact with a little work one can obtain an altimeter reading within +/- 1M the sensors are so accurate. (I haven't tested that claim yet) It communicates with the Arduino via the I2C interface. The address must be set either high or low as if it is left at default it won't work. To set the address high (0x76) use a 10k resistor and connect it to power. If you connect it to ground in the same fashion it will use the low address (0x77). 
<P>
<I>A good troubleshooting tool to use when first working with I2C is an I2C Scanner. There is a copy of it in my github. I have started a cheatsheet list of the devices I have and what addresses they have. Each time I get a new one I will run it against i2c to make sure it works and see what address to use. </I>
<P>
Here is a link to the <A HREF="https://www.bosch-sensortec.com/bst/products/all_products/bmp280">BMP280 datasheet.</A>
<P>
And here is the link to the <A HREF="https://github.com/sparkfun/SparkFun_BME280_Arduino_Library">BME280 library </A>used here. 
<H2>The LCD</H2>
<P>

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
The LCD is based on the old Nokia 5110 LCD screen used in their past phones. It is a decent sreen and easy to find. Its' display is 48 rows by 84 columns. It has a PCD8544 controller used for all LCD functions. This model uses SPI for its communication with the Arduino. There are other ones out there that use the I2C protocol which only requires 4 pins. There are some different libraries out there too. I used xxx in this project. The basic functions are well-documented and they also have an additional library with graphical functions. 

<I>To Do:</I>
<BR>
<I>Keeping some historical data and being able to graph them over time is a good additional project. One could store the data on an SD card or rely it via wireless. There is a section of code that shows how to output data in a CVS format for later analysis. </I>
<P>
The library used is <A HREF="http://www.rinkydinkelectronics.com/download.php?f=LCD5110_Basic.zip">located here.</A> 
<P>

