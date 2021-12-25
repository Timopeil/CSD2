enum Oscilator { sine, square, ramp};
Oscilator = sine;
switch(sine)
{
    case sine  : std::cout << "sine\n";   break;
    case square: std::cout << "gsquare\n"; break;
    case ramp : std::cout << "ramp\n";  break;
}
