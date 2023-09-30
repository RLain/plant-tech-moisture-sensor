I bought the wrong part for the initial setup. The FC-50 is a relay module awith NO/C/NC ports:

`NO/NC/C`: https://www.circuitbasics.com/setting-up-a-5v-relay-on-the-arduino/. See the `fc-50_circuit_diagram.png` in this repo for positions of the connections. The `fc-50_CMU-circuit_diagram.png` is the relay module I purchased [JQF-3ff-S-Z](https://www.communica.co.za/products/cmu-moisture-sensor-with-relay?variant=40204733055049) however if you compare the images they are the same.

💡 When holding the relay module so the writing is legible, the left hand connections are top-to-bottom order: NO -> COMM -> NC.

Replaced with the [LM393](https://www.communica.co.za/products/bmt-soil-moisture-sensor-kit).
