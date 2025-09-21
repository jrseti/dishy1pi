# Power Supply

This directory contains the design files and documentation for the power supply unit used in the Dishy1Pi project. The power supply is responsible for providing the necessary voltage and current to the Dishy1Pi Hat and its connected components.

This will be a test power supply 12-24VDC in and 5VDC out at up to 1A.
The design files include schematics, PCB layouts, and a bill of materials (BOM) for the components used in the power supply.

Used TI's WEBENCH Power Designer to design the power supply around the TPS62932 buck converter IC. Link: https://webench.ti.com/power-designer/

Out of the myriad of chioces I selected to use the TPS62932DRLR. See the full report, in PDF, created by WEBENCH. Power Supply Report: [power_supply_report.pdf](docs/PowerSupplyDesignReport.pdf)

![Schematic](images/power_supply_schematic.png)


| Name  | Manufacturer     | Part Number              | Properties                                                                 | Qty | Footprint      | LCSC | Notes |
|-------|------------------|--------------------------|----------------------------------------------------------------------------|-----|----------------|------|-------|
| Cboot | MuRata           | GRM155R71A104KA01D       | Series=X7R;<br>Cap=100.0 nF<br>ESR=1.0 mΩ;<br>VDC=10.0 V;<br>IRMS=0.0 A   | 1   | 0402 3 mm²     |      |       |
| Cff   | TDK              | CGA1A2C0G1E180J030BA     | Series=C0G/NP0;<br>Cap=18.0 pF;<br>VDC=25.0 V;<br>IRMS=0.0 A              | 1   | 0201 2 mm²     |      |       |
| Cin   | Taiyo Yuden      | MSASU32MSB5106KPNA01     | Series=X5R;<br>Cap=10.0 µF;<br>ESR=3.979 mΩ;<br>VDC=50.0 V;<br>IRMS=3.4821 A | 1   | 1210 15 mm²    |      |       |
| Cinx  | TDK              | CGA3E2X7R1H104K080AA     | Series=X7R;<br>Cap=100.0 nF;<br>ESR=29.6 mΩ;<br>VDC=50.0 V;<br>IRMS=971.99 mA | 1   | 0603 5 mm²     |      |       |
| Cout  | MuRata           | GRM32ER61C476KE15L       | Series=X5R;<br>Cap=47.0 µF;<br>ESR=3.037 mΩ;<br>VDC=16.0 V;<br>IRMS=4.59346 A | 1   | 1210_280 15 mm²|      |       |
| Css   | MuRata           | GRM155R71A333KA01D       | Series=X7R;<br>Cap=33.0 nF;<br>ESR=1.0 mΩ;<br>VDC=10.0 V;<br>IRMS=0.0 A   | 1   | 0402 3 mm²     |      |       |
| L1    | Bourns           | SRR1208-100ML            | L=10.0 µH; DCR=21.0 mΩ                                                     | 1   | SRR1208 216 mm²|      |       |
| Rfbb  | Vishay-Dale      | CRCW040210K0FKED         | Series=CRCW..e3; Res=10.0 kΩ; Power=63.0 mW; Tol=1.0%                      | 1   | 0402 3 mm²     |      |       |
| Rfbt  | Yageo            | RC0603FR-0752K3L         | Res=52.3 kΩ; Power=100.0 mW; Tol=1.0%                                      | 1   | 0603 5 mm²     |      |       |
| U1    | Texas Instruments| TPS62932DRLR             | Switcher IC                                                                | 1   | DRL0008A-MFG 9 mm² |  |       |
