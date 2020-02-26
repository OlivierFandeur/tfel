% New functionalities of the 3.4 version of `TFEL`, `MFront` and `MTest`
% Thomas Helfer
% 2020

\newcommand{\paren}[1]{{\left(#1\right)}}

The page declares the new functionalities of the 3.4 version of the
`TFEL` project.

# New features of `MFront`

## Improvement of the `StandardElastoViscoplasticity` brick

### The `Power` isotropic hardening rule{#sec:power_isotropic_hardening_rule}

The `Power` isotropic hardening rule is defined by:
\[
R\paren{p}=R_{0}\,\paren{p+p_{0}}^{n}
\]

#### Options

The `Power` isotropic hardening rule expects at least the following
material properties:

- `R0`: the coefficient of the power law
- `n`: the exponent of the power law

The `p0` material property is *optional* and generally is considered a
numerical parameter to avoir an initial infinite derivative of the power
law when the exponent is lower than \(1\).

#### Example

The following code can be added in a block defining an inelastic flow:

~~~~{.cpp}
    isotropic_hardening : "Linear" {R0 : 50e6},
    isotropic_hardening : "Power" {R0 : 120e6, p0 : 1e-8, n : 5.e-2}
~~~~

# Tickets solved during the development of this version

## Ticket #209: lack of documentation of the `@GasEquationOfState` keyword

This feature is now described in the (`MTest` page)[mtest.html]

For more details, see: <https://sourceforge.net/p/tfel/tickets/209/>

## Ticket #205: Add power isotropic hardening rule

This feature is described in Section
@sec:power_isotropic_hardening_rule.

For more details, see: <https://sourceforge.net/p/tfel/tickets/205/>

## Ticket #195 : Export variables bounds for material properties

Variables bounds (both @Bounds and @PhysicalBounds) are now available for material properties. 
They are available directly in the .so file via getExternalLibraryManager().

For more details, see: <https://sourceforge.net/p/tfel/tickets/195/>

## Ticket #196 : Export variable names for all interface of material property

The variable name of material property was available only for castem interface. 
Now it is available for all interface (c++, python, …). 
The name can be found in the .so file via getExternalLibraryManager().

For more details, see: <https://sourceforge.net/p/tfel/tickets/196/>

# References