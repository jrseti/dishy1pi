# Power Supply circuit based on the MP2322 Buck Chip
This is a simple PCB to test creating several voltages that are used on the Dishy1Pi PCB. Once this cirction is tested as working, the relevant schematic parts will be moved over to the DishyPi1 schematic. The voltages needed are:
- 12V to power each of the 2 encoders. This voltage is supplied from an external power supply and protected by a PTC fuse on the Dishy1Pi PCB. Also reverse polatiry protected.
- 5V to power the logic circuity on the Dishy1Pi PCB.

The buck chip is the MP2322 from Monolithic Power Systems. Link to datasheet: https://www.monolithicpower.com/en/documentview/productdocument/index/version/1/document_type/Datasheet/lang/en/sku/MP2322

