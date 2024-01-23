# C++ - Module 03

## Exercise 00: Aaaaand... OPEN!

```
Exercise : 00
Aaaaand... OPEN!
Turn-in directory : ex00/
Files to turn in : FragTrap.cpp FragTrap.hpp main.cpp
Forbidden functions : None
```

Here you have to make a class that models the FR4G-TP assault robot/shoebox.

The class will be called FragTrap, and will have the following attributes, initialized to the specified values:

- Hit points (100)
- Max hit points (100)
- Energy points (100)
- Max energy points (100)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (30)
- Ranged attack damage (20)
- Armor damage reduction (5)

You will also give it a few functions to make it more life-like:

- rangedAttack(std::string const & target)
- meleeAttack(std::string const & target)
- takeDamage(unsigned int amount)
- beRepaired(unsigned int amount)

In all of these functions, you have to display something to describe what happens. For example, the rangedAttack function may display something along the lines of:

**FR4G-TP attacks at range, causing points of damage!**

The constructor and destructor must also display something, so people can see they have been called properly. Bonus points if these messages are funny references (If you don’t know what a FR4G-TP is, Google it at least, and use a few well-chosen quotes ...)

A few constraints:

- The number of hit points can never exceed the number of max hit points. Same for the energy points. If, for example, you repair too much HP, then you set them to the max HP number. In the same way, they can’t fall below 0.
- When you take damage, you have to take your armor damage reduction into account.

Finish by adding a vaulthunter_dot_exe(std::string const & target) function, that will effect a semi-random attack on the target. Make it so each time it is called, it chooses a (preferably) funny attack chosen at random from a pool of at least 5 possible attacks. Whatever you want to use to accomplish this is fine, but as usual, the more elegant your method, the better. This function costs 25 energy points to run. If you don’t have enough energy points, it will do nothing else than print something indicating it’s out of energy.

You will provide a main function, with enough tests to demonstrate that your code is functional.

## Exercise 01: Serena, my love!

```
Exercise : 01
Serena, my love!
Turn-in directory : ex01/
Files to turn in : Same as previous exercise + ScavTrap.cpp ScavTrap.hpp
Forbidden functions : None

```

Because we can’t ever have enough Claptraps, now you will make another one that serves a slightly different purpose: Manning the door of your soon-to-be evil lair, and challenging people who want to come in.

The class will be named ScavTrap, and will have these attributes:

Hit points (100)

- Max hit points (100)
- Energy points (50)
- Max energy points (50)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (20)
- Ranged attack damage (15)
- Armor damage reduction (3)

Add the same functions as in the FragTrap, but the constructor, destructor, and attacks have to use different outputs. After all, a Claptrap has to have some measure of individuality.

The one exception will be that the ScavTrap doesn’t have a vaulthunter_dot_exe function. Instead, it has a challengeNewcomer function, which makes the ScavTrap choose a challenge at random from a set of various (and hopefully funny) challenges you will have to invent, and print it on the standard output.

Extend your main function to test both classes.

## Exercise 02: Repetitive work

```
Exercise : 02
Repetitive work
Turn-in directory : ex02/
Files to turn in : Same as previous exercise + ClapTrap.cpp ClapTrap.hpp
Forbidden functions : None

```

Making Claptraps is probably starting to get on your nerves, isn’t it?

Well, before you can work less, you have to work more.

Now you will make a ClapTrap class, that both FragTrap and ScavTrap will inherit from.

You will put all the common functions in the ClapTrap class, but the specific functions must remain where they are. In other words, you must make sure that the FragTrap and ScavTrap classes contain only what isn’t shared between the both of them, and put everything they both share in the parent class.

The ClapTrap class will have its own construction and destruction messages. Also, proper construction/destruction chaining must be present (When you build a FragTrap, you must start by building a ClapTrap... Destruction is in reverse order), and the tests have to show it.

## Exercise 03: Now it’s easier!

```
Exercise : 03
Now it’s easier!
Turn-in directory : ex03/
Files to turn in : Same as previous exercise + NinjaTrap.cpp NinjaTrap.hpp
Forbidden functions : None

```

Using everything you have done before, make a NinjaTrap, with the following attributes:

- Hit points (60)
- Max hit points (60)
- Energy points (120)
- Max energy points (120)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (60)
- Ranged attack damage (5)
- Armor damage reduction (0)

Its special attack will be the ninjaShoebox function. There will be multiple functions with the same signature, each taking a reference to a different Claptrap as parameter (including the NinjaTrap), and having a different action. Too bad there isn’t a way to make it take ANY Claptrap but still react in specific ways... Oh well, you’ll see tomorrow. Even I don’t know what it does exactly, make it do something funny.

As usual, your main will be extended to test the new class.

Do you notice how easy it is to make a new Claptrap now that you have a parent class for it?

## Exercise 04: Ultimate assault shoebox

```
Exercise : 04
Ultimate assault shoebox
Turn-in directory : ex04/
Files to turn in : Same as previous exercise + SuperTrap.cpp SuperTrap.hpp
Forbidden functions : typeid() and more, read the warnings

```

Now, you will combine the best of both worlds by making a Claptrap that’s half Fragtrap, half Ninjatrap.

It will be named SuperTrap, and it will inherit from both the FragTrap AND the NinjaTrap.

Its attributes and functions will be chosen from either of its parent classes:

- Hit points (Fragtrap)
- Max hit points (Fragtrap)
- Energy points (Ninjatrap)
- Max energy points (Ninjatrap)
- Level (1)
- Name (Parameter of constructor)
- Melee attack damage (Ninjatrap)
- Ranged attack damage (Fragtrap)
- Armor damage reduction (Fragtrap)
- rangedAttack (Fragtrap)
- meleeAttack (Ninjatrap)

It will have the special attacks of both.

As usual, your main will be extended to test the new class.

Of course, the Claptrap part of the Supertrap will have to be created once, and only once... Yes, there’s a trick. Look it up.