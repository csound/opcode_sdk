<CsoundSynthesizer>
<CsOptions>
</CsOptions>
<CsInstruments>
0dbfs=1

instr 1
i1 = 2
i2 = 2
i3 mult i1, i2
print i3
endin

instr 2
k1 = 2
k2 = 2
k3 mult k1, k2
printk2 k3
endin

instr 3
a1 oscili 0dbfs, 440
a2 oscili 0dbfs, 356
a3 mult a1, a2
 out a3
endin

</CsInstruments>
<CsScore>
i1 0 0
i2 0 1
i3 0 2
</CsScore>
</CsoundSynthesizer>