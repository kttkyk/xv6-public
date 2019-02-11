#!/usr/bin/env python3

# Output entrypgtab which maps [0, 4MB) -> [0, 4MB)

# __attribute__((__aligned__(PGSIZE)))
# pde_t entrypgdir[NPDENTRIES] = {
#   // Map VA's [0, 4MB) to PA's [0, 4MB)
#   [0] = (0) | PTE_P | PTE_W | PTE_PS,
#   // Map VA's [KERNBASE, KERNBASE+4MB) to PA's [0, 4MB)
#   [KERNBASE>>PDXSHIFT] = (0) | PTE_P | PTE_W | PTE_PS,
# };


print("__attribute__((__aligned__(PGSIZE)))")
print("pde_t entrypgtab[NPTENTRIES] = {")

addr_page = 0
while addr_page < 4 * 1024 * 1024:
    print("  (0x{:06x}) | PTE_P | PTE_W,".format(addr_page))
    addr_page += 4 * 1024

print("};")
