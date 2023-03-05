# Garden Automation Node
bringing IoT into your garden (kind of)

## This is finished product
<p align="center">
  <img src="" alt="There is no image becouse I am still working on it :)">
<p/>

## Mile stones
 1. What do I want to achive? ✔️
 2. Block diagram ✔️
 3. Decide on components ✔️
 4. Gather all necessary parts ✔️
 5. Desing PCB ✔️
 6. Start CODING (fun part)
 7. Wait 4ever till they finally arrive ✔️
 8. Assemble thing
 9. Realise that I've made mistakes...
 10. FIX IT
 11. If You are still reading this list, I appreciate it,
 12. Testing code on living organism
 13. Enjoy... :)
 
## What do I want to achive?
My family has a house in the country. We also have garden, quite big garden even with two (at least right now) greenhouses. Waterring all plants, making sure that they won't boil inside of greenhouse or tunnel is a bit time consuming and boring saying the least. As an automation engeener (XD) I would like to automate some stuff to make it easier for my parents to grow croops. 
> All in all I want to make my garden SMART - (kind of)


## Block diagram

So the main idea behind this project component-wisely is as shown below.
<p align="center">
  <img src="https://user-images.githubusercontent.com/96399051/212779657-200469cc-1a19-4963-b610-1efc629f71ea.png" alt="Block diagram of Externally powered node">
<p/>
Sorry for multilingualism but I deleted my draw.io diagram and was lazy and lef It as it is (in Polski język). For all You non Polish people (If anybody is even reading this XD):

  - ESP32 as brain of the system,
  - few digital inputs, 
  - analog inputs, 
  - OneWire input, 
  - onboard humidity, temperature and pressure sensor, 
  - powered by 24V,
  - hermetic enclosure.

 ## Decide on components
As mentioned beefore - I used ESP32, for onboard conditions sensor I want to use BMP280, becouse I want to use analog measuring of ground humidity - I need to have classic analog input, for temperature measuring I want to use DS18B20 - cheap and easy to use sensor. Digital outupts will be done by electromagnetic relays, digital inputs will be done by octocouplers. Additionally step down converter for changing 24V power supply volatage to something like 5VDC.

## Gather all necessary parts
<p align="center">
  <img src="" alt="Image of my parts pile, I am still gathering them...">
<p/>

## Desing PCB
I started designing this project quite long ago and went through few iterations. This is how last iteration is going to look like:
<p align="center">
  <img width=700 src="https://user-images.githubusercontent.com/96399051/219206965-d66beead-bf75-472c-a1f2-4415c399338a.png" alt="IMG of PCB">
<p/>
Thats all for now. Progress is low becouse I have to keep my other more important projects up to date. We will see how it will go. I have high hopes for this one actually.

# I have gathered all parts, and ordered PCBs - time for waiting
<p align="center">
  <img width=400 src="https://user-images.githubusercontent.com/96399051/222723082-736f6965-3bbf-4de7-9e4b-33913cc176df.png" alt="production done">
<p/>

# PCBs arrived
Their trip took only 8 days - nice. Now I have to get them to my place from my parents house :)

# A little pre render
<p align="center">
  <img width=800 src="https://user-images.githubusercontent.com/96399051/222533701-96219be4-5b1e-4cbb-ae1a-1e9b635c46ff.png" alt="Render of project">
<p/>
I know It's missing some parts, but all in all looks quite good at least for me :D
