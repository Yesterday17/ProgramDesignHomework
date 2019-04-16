const comps = [];
let index = 0;

function newC(name, type, man) {
  comps.push({
    index: index++,
    name: name,
    type: type,
    manufacturer: man
  });
}

newC("RTX", "RTX 2060", "NVIDIA");
newC("RTX", "RTX 2070", "NVIDIA");
newC("RTX", "RTX 2080", "NVIDIA");

newC("GTX", "1660", "NVIDIA");
newC("GTX", "1660-Ti", "NVIDIA");

newC("GTX", "1060", "NVIDIA");
newC("GTX", "1070", "NVIDIA");
newC("GTX", "1070-Ti", "NVIDIA");
newC("GTX", "1080", "NVIDIA");
newC("GTX", "1080-Ti", "NVIDIA");

newC("Core-i9", "9900K", "Intel");
newC("Core-i9", "9900KF", "Intel");

newC("Core-i7", "9700K", "Intel");
newC("Core-i7", "9700KF", "Intel");

newC("Core-i5", "9600K", "Intel");
newC("Core-i5", "9600KF", "Intel");
newC("Core-i5", "9400", "Intel");
newC("Core-i5", "9400F", "Intel");

newC("Core-i3", "9350KF", "Intel");

newC("Ryzen-7", "3750H", "AMD");
newC("Ryzen-7", "3700U", "AMD");
newC("Ryzen-7", "2700X", "AMD");
newC("Ryzen-7", "2700", "AMD");
newC("Ryzen-7", "2700E", "AMD");

newC("Ryzen-5", "3550H", "AMD");
newC("Ryzen-5", "3500U", "AMD");
newC("Ryzen-5", "2600X", "AMD");
newC("Ryzen-5", "2600", "AMD");
newC("Ryzen-5", "2500X", "AMD");

newC("Ryzen-3", "3300U", "AMD");
newC("Ryzen-3", "3200U", "AMD");
newC("Ryzen-3", "2300X", "AMD");
newC("Ryzen-3", "2300U", "AMD");
newC("Ryzen-3", "1300X", "AMD");

JSON.stringify(comps);
