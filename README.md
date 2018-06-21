Plugin Opcode SDK
-------------------

This SDK was designed to help third-party plugin opcode development
either in C or C++. Its only dependency is a Csound installation.

Contents
===========

1. CMake scripts: a CMakeLists.txt containing the basic elements to
build an opcode. This in turns depends on the FindCsound module,
which is also provided to discover a Csound installation. The
CMake script builds the opcode examples provided in the SDK.

2. C opcodes example: a trivial example showing how to
begin writing opcodes in C. For further information on this,
check the Csound Reference or the Csound FLOSS Manual
(http://write.flossmanuals.net/csound/extending-csound/)

3. C++ opcodes example: a C++ version of the same trivial
example, using the Csound Plugin Opcode Framework.
For further information, check the paper describing this
at http://www.mdpi.com/2076-3417/7/10/970

4. A CSD example for these opcodes.

