# my_radar

A high-performance C simulation of an air traffic environment where aircraft navigate toward destinations, incorporating real-time collision detection and safety zones managed by control towers.

---

## 🧠 Description

This project implements a 2D kinematic simulation where autonomous aircraft move toward specific targets. The system calculates spatial proximity between entities to trigger destruction events upon collision, unless the aircraft are localized within the operational radius of a control tower.

---

## 🚀 Getting started

### Dependencies

* CSFML 2.6.0

### Installing

**Clone the repository:**

```bash
git clone https://github.com/QUINTIN-Killian/my_radar.git
cd my_radar
```

### Executing program

**Compiling:**

```bash
make
```

**Executing:**

```bash
./my_radar <config_file>
```

Example:

```bash
./my_radar script_file.rdr
```

A config file can be generated using the `my_generator.py` binary. Launch `python3 my_generator.py -h` to get help.

---

## 👥 Authors

* [@Killian QUINTIN](https://github.com/QUINTIN-Killian)
