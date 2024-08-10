# Electronic dice demo (STM32L432KC)
An STM32 HAL example of an electronic die/dice[^1].

[^1]: [Dice vs. Die – Which Is Singular and Which Is Plural?](https://grammarist.com/usage/dice-die/) (Grammarist)

![Charlie with a dice in action](/Assets/Images/charlie_with_dice_in_action.jpg)

The main goal for this example is to lure you into experimenting with the (T)RNG peripheral of the STM32 uC. The example also implements the Charlieplexing technique to reduce the pin count. Here Charlieplexing is performed in the blocking mode. It is just for the concept demonstration purposes - to deploy it in a control system you have to rewrite the code into a non-blocking one. Before we move on I must confess that my agenda is much more evil - I want to lure you into the world of unpredictability manifested by radioactive decay :radioactive:, quantum mechanics :atom: and chaotic systems :game_die: [^2]

[^2]: Randomness, uncertainty, chaos and unpredictability are not synonyms if we want to be rigorous. For example, rolling dice create a chaotic system, even a single rolling die creates a chaotic system with the environment it interacts with, whose behavior is highly sensitive to initial conditions - when we roll dice we do NOT intend to exploit the fundamental unpredictability at the level of a quantum event (such as a single atom's decay).

# Why electronic dice?
Because it's fun. Because they are more versatile - you can emulate any RPG dice in practically no time. And they are usually much more fair than an unbalanced/imperfect/unsymmetrical physical dice. "The RNG is a true random number generator that continuously provides 32-bit entropy samples, based on an analog noise source. (...) The RNG true random number generator has been tested using NIST statistical test suite SP800 rev1a (April 2010)." [[RM0394]](https://www.st.com/resource/en/reference_manual/rm0394-stm32l41xxx42xxx43xxx44xxx45xxx46xxx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf). 

# Missing files?
Don't worry :slightly_smiling_face: Just hit Alt-K to generate /Drivers/CMCIS/ and /Drivers/STM32L4xx_HAL_Driver/ based on the .ioc file. After a couple of seconds your project will be ready for building.

# Libraries
* OLED: [stm32-ssd1306](https://github.com/afiskon/stm32-ssd1306) (MIT license)

# Exemplary hardware
* [OLED display 1.3" (SH1106 or SSD1306)](https://sklep.msalamon.pl/produkt/wyswietlacz-oled-13-i2c-bialy/)

# IMHO useful gadgets
* [everActive 6F22/9V Li-ion 550 mAh Professional Line](https://everactive.eu/sites_collections/product/788)

# Readings and videos
## Randomness
* [Introduction to Randomness and Random Numbers](https://www.random.org/randomness/)

## Probabilistic thinking
* [Monty Hall problem](https://en.wikipedia.org/wiki/Monty_Hall_problem) (Wikipedia)
* [P-value, a true test of statistical significance? A cautionary note](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4111019/) (Tukur Dahiru)
* [Birthday problem](https://en.wikipedia.org/wiki/Birthday_problem) (Wikipedia)
* [Misuse of p-values](https://en.wikipedia.org/wiki/Misuse_of_p-values) (Wikipedia)

And now exercise your critical thinking skills

* [Arduino Roll The Dice](https://www.youtube.com/watch?v=74jCuh-_foU)

## Humans as weak sources of entropy
* [Randomness is Random - Numberphile](https://www.youtube.com/watch?v=tP-Ipsat90c)
* [Man vs. Machine.](https://www.loper-os.org/bad-at-entropy/manmach.html)
* [How random can you be?](https://www.expunctis.com/2019/03/07/Not-so-random.html) (Ilya Perederiy)
* [Benford's law and accounting fraud detection](https://en.wikipedia.org/wiki/Benford%27s_law) (Wikipedia)
* [Almost All Random Numbers Are Actually Fake](https://www.youtube.com/watch?v=JmuXwbirmZQ) (Thoughty2)
* [The Incredible Story Of Randomness](https://www.youtube.com/watch?v=iT20A4KQxyM) (New Mind)

## Physical dice fairness
* [Standard polyhedral dice optimized for fairness](https://www.mathartfun.com/thedicelab.com/OptiDice.html)
* [d20 Dice Randomness Test: Chessex vs GameScience](https://www.awesomedice.com/blogs/news/d20-dice-randomness-test-chessex-vs-gamescience)
* [Optidice](https://www.youtube.com/watch?v=BUaY8ycvtM0) (Henry Segerman)

## Charlieplexing
* [Charlieplexing](https://en.wikipedia.org/wiki/Charlieplexing) (Wikipedia)
* [NEW Arduino Uno R4 Boards - Minima & WiFi](https://www.youtube.com/watch?v=kJE9CBb3fT8) (DroneBot Workshop)

# Next steps
Hooked on randomness? Good! This is just the first chapter. Now test the RNG on your own. Use STM32 as USB HID keyboard to feed the data directly into an online bitstream tester that implements the NIST Statistical Test Suite for Random and Pseudorandom Number Generators such as [https://mzsoltmolnar.github.io/random-bitstream-tester/](https://mzsoltmolnar.github.io/random-bitstream-tester/). Or use UART if you are up to more than, let's say, 1000 bits - it's much faster. Then build your own TRNGs. Experiment with different sources of entropy. A Geiger counter[^3]. A thermal noise (ADC)[^4]. A physical dice roller with automatic face detection[^5]. I will join you along the way with my contraptions if time allows :watch: And first and foremost, never ever trust your gut when assessing randomness. We humans tend to be very bad at that. Successful thinking in terms of probabilities, including the probabilities of probabilities, probability density functions and Bayesian probabilities, without proper training is usually hard - explore [Readings and videos](#readings-and-videos) for some illustration of that. Train yourself in probabilistic thinking. Funny thing is that thinking itself can be regarded as the process of using all the stats being continuously stored in your brain. For example, learning a natural language is a Bayesian endeavour.

[^3]: [Arduino True Random Number Generator](https://www.instructables.com/Arduino-True-Random-Number-Generator/) (Instructables)
[^4]: [A true random number generator that utilizes thermal noise in a programmable system-on-chip (PSoC)](https://onlinelibrary.wiley.com/doi/abs/10.1002/cta.3046) by Shunsuke Matsuoka, Shuichi Ichikawa and Naoki Fujieda
[^5]: [Fair Dice Tester (Pt. 1)](https://gerry-chen.com/projects/fairdicetester/) by Gerry Chen

# Call for action
Create your own [home laboratory/workshop/garage](http://ufnalski.edu.pl/control_engineering_for_hobbyists/2024_dzien_otwarty_we/Dzien_Otwarty_WE_2024_Control_Engineering_for_Hobbyists.pdf)! Get inspired by [ControllersTech](https://www.youtube.com/@ControllersTech), [DroneBot Workshop](https://www.youtube.com/@Dronebotworkshop), [Andreas Spiess](https://www.youtube.com/@AndreasSpiess), [GreatScott!](https://www.youtube.com/@greatscottlab), [ElectroBOOM](https://www.youtube.com/@ElectroBOOM), [Phil's Lab](https://www.youtube.com/@PhilsLab), [atomic14](https://www.youtube.com/@atomic14), [That Project](https://www.youtube.com/@ThatProject), [Paul McWhorter](https://www.youtube.com/@paulmcwhorter), and many other professional hobbyists sharing their awesome projects and tutorials! Shout-out/kudos to all of them!

> [!WARNING]
> Automation and control engineering - do try this at home :exclamation:

190+ challenges to start from: [Control Engineering for Hobbyists at the Warsaw University of Technology](http://ufnalski.edu.pl/control_engineering_for_hobbyists/Control_Engineering_for_Hobbyists_list_of_challenges.pdf).

Stay tuned!
