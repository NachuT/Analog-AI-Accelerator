# Analog AI Accelerator
Essentially what this project aims to be is a proof of concept for a trend that has been taking please in tech recently which is the use of CIM (Compute in Memory) systems to perform AI inference operations. More spceifically AI inference relies on MAC (Multiply Accumulate) Multiplication which can be emulated with analog electronics saving valuable power that is often wasted due to the need of using RAM. The way the analog alternative works is by using DACs to convert signals into Analog voltages and multiply them through a MOSFET biased in the triode region to create linear multiplication to a current which is then summed and outputted as a voltage via a transimpedance amplifier. This output is then read by an ADC for the inference model to use.


Overall, this costs around 50 dollars to produce with the Pico costing 10$ and the Board from JLCPCB costing 40$.
## Schematic 
<img width="1045" height="562" alt="Screenshot 2026-06-26 at 2 22 58 PM" src="https://github.com/user-attachments/assets/63d315d5-ea91-428d-854c-73592de3082e" />

## PCB
<img width="631" height="356" alt="Screenshot 2026-06-26 at 2 23 34 PM" src="https://github.com/user-attachments/assets/e0a63728-f36b-4e1c-811f-81f06827a3bc" />

## 3d view
<img width="1047" height="614" alt="Screenshot 2026-06-26 at 2 24 19 PM" src="https://github.com/user-attachments/assets/64e107f6-0904-4748-b883-c10848898576" />
