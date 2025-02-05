# include <iostream>
// #include <drogon/drogon.h>

using namespace std;
using namespace std::chrono;

struct GearFunctions {
    double m; // Slope
    double b; // Y-Intercept
};

constexpr GearFunctions gears[] = {
    {0.00509412, 0.0529412},
    {0.00658235, 0.233824},
    {0.00838235, 0.0588235},
    {0.0107088, 0.0705882},
    {0.0138147, 0.442647},
    {0.0176382, 0.0941176},
    {0.0223824, 0.0588235},
    {0.0290118, 0.194118},
    {0.0367676, 0.0411765}
};


int main(){
    double speed;
    cout << "Enter the current speed: ";
    cin >> speed;

    auto start = high_resolution_clock::now();

    if (speed < 30){
        cout << "Shift to 1, now at " << floor((speed - gears[0].b) / gears[0].m) << " rpm." << endl;
    } else if (speed < 38){
        cout << "Shift to 2, now at " << floor((speed - gears[1].b) / gears[1].m) << " rpm." << endl;
    } else if (speed < 48){
        cout << "Shift to 3, now at " << floor((speed - gears[2].b) / gears[2].m) << " rpm." << endl;
    } else if (speed < 63){
        cout << "Shift to 4, now at " << floor((speed - gears[3].b) / gears[3].m) << " rpm." << endl;
    } else if (speed < 79){
        cout << "Shift to 5, now at " << floor((speed - gears[4].b) / gears[4].m) << " rpm." << endl;
    } else if (speed < 101){
        cout << "Shift to 6, now at " << floor((speed - gears[5].b) / gears[5].m) << " rpm." << endl;
    } else if (speed < 131){
        cout << "Shift to 7, now at " << floor((speed - gears[6].b) / gears[6].m) << " rpm." << endl;
    } else if (speed < 165){
        cout << "Shift to 8, now at " << floor((speed - gears[7].b) / gears[7].m) << " rpm." << endl;
    } else if (speed >= 165){
        cout << "Shift to 9, now at " << floor((speed - gears[8].b) / gears[8].m) << " rpm." << endl;
    } else {
        cout << "Error, no gear found" << endl;
    }

    auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "Execution Time: " << duration.count() << " microseconds\n";

    return 0;
}



// int main() {
//     drogon::app().addListener("0.0.0.0", 8080);
//     drogon::app().registerHandler("/api/hello", [](const drogon::HttpRequestPtr &, std::function<void(const drogon::HttpResponsePtr &)> callback) {
//         auto response = drogon::HttpResponse::newHttpJsonResponse({{"message", "Hello from C++"}});
//         callback(response);
//     });
//     drogon::app().run();
// }