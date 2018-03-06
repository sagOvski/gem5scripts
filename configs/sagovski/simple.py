# Creating while following Learning gem5 HPCA tutorial - Part 1

import m5
from m5.objects import *
# imports all the SimObjects compiled into the namespace of this python class

# system being simulated
system = System()

system.clk_domain = SrcClockDomain()
system.clk_domain.clock = '1GHz'
system.clk_domain.voltage_domain = VoltageDomain() # Default values will be set

system.mem_mode = 'timing' # Can be atomic, timing. timing is the usual mode

system.mem_ranges = [AddrRange('512MB')] # physical memory ranges, only one in this case

# cpu

system.cpu = TimingSimpleCPU() # Single cycle cpu except for memory operations.

system.membus = SystemXBar() #

#hooking cpu to system bus
system.cpu.icache_port = system.membus.slave
system.cpu.dcache_port = system.membus.slave

# int controllers
system.cpu.createInterruptController()
system.cpu.interrupts[0].pio = system.membus.master
system.cpu.interrupts[0].int_master = system.membus.slave
system.cpu.interrupts[0].int_slave = system.membus.master

system.system_port = system.membus.slave

system.mem_ctrl = DDR3_1600_8x8()
system.mem_ctrl.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.master


process = Process()
process.cmd = ['tests/test-progs/hello/bin/x86/linux/hello'] 
system.cpu.workload = process
system.cpu.createThreads()

# all the simulations have to have a root object, absolutely required,
# all others are optionsl 
root = Root(full_system=False, system = system)

# walk through all the above python objects and create all C++ objects
m5.instantiate()

print "beginning simulation" 
exit_event = m5.simulate()

print "done simulating at tick %d because %s!!" %(m5.curTick(), exit_event.getCause()) 

