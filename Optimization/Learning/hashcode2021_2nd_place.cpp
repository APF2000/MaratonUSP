// https://www.kaggle.com/sagishporer/2nd-place-solution-4508721

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <assert.h>
#include <chrono>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;
using namespace std::chrono;

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

//#define INPUT_FILE "C:/Temp/hashcode/hashcode.in"
//#define OUTPUT_FILE "C:/Temp/hashcode/hashcode.in.cpp.out"
#define INPUT_FILE "1.in"
#define OUTPUT_FILE "submission.csv"

#define THREAD_COUNT 4

class Street {
public:
    int UniqueID;
    int StartIntersection;
    int EndIntersection;
    string Name;
    int Length;

    int IncomingUsageCount;
    int CarsOnStart;

    Street(int uniqueId, int startIntersection, int endIntersection, string name, int length) {
        this->UniqueID = uniqueId;
        this->StartIntersection = startIntersection;
        this->EndIntersection = endIntersection;
        this->Name = name;
        this->Length = length;
        this->IncomingUsageCount = 0;
        this->CarsOnStart = 0;
    }
};

class Car {
public:
    int UniqueID;
    vector<Street*> Streets;

    Car(int uniqueId, vector<Street*> streets) {
        this->UniqueID = uniqueId;
        this->Streets = streets;
    }

    int timeNeedToDrive() {
        int time = 0;
        for (int i = 1; i < Streets.size(); i++)
            time += Streets[i]->Length;

        return time;
    }
};

class Intersection {
public:
    int ID;
    vector<Street*> IncomingStreets;
    vector<Street*> OutgoingStreets;

    Intersection(int id) {
        this->ID = id;
    }
};

class CarSimultionPosition {
public:
    Car* MyCar;
    int StreetNumber;
    int TimeGotHere;
    int TimeLeftOnDrive;
    vector<int> StreetLength;
    vector<int> StreetUniqueID;
    vector<int> StreetEndIntersection;

    CarSimultionPosition(Car* car, int timeGotHere) {
        this->MyCar = car;
        init(timeGotHere);

        for (int i = 0; i < MyCar->Streets.size(); i++) {
            StreetUniqueID.push_back(MyCar->Streets[i]->UniqueID);
            StreetEndIntersection.push_back(MyCar->Streets[i]->EndIntersection);
            StreetLength.push_back(MyCar->Streets[i]->Length);
        }
    }

    void init(int timeGotHere) {
        this->StreetNumber = 0;
        this->TimeGotHere = timeGotHere;
        this->TimeLeftOnDrive = MyCar->timeNeedToDrive();
    }

    Street* getCurrentStreet()
    {
        return MyCar->Streets[StreetNumber];
    }

    static bool compareByTimeGotHere(CarSimultionPosition* a, CarSimultionPosition* b) {
        return a->TimeGotHere < b->TimeGotHere;
    }
};

template< typename T, typename Pred >
typename std::vector<T>::iterator
insert_sorted(std::vector<T>& vec, T const& item, Pred pred)
{
    return vec.insert
    (
        std::lower_bound(vec.begin(), vec.end(), item, pred),
        item
    );
}

class Problem {
public:
    int Duration;
    int BonusPerCar;
    vector<Intersection*> Intersections;
    vector<Street*> Streets;
    vector<Car*> Cars;

    ~Problem() {
        for (Street* street : Streets)
            delete street;
        for (Intersection* intersection : Intersections)
            delete intersection;
        for (Car* car : Cars)
            delete car;
    }

    int calculateScoreUpperBound() {
        int upperBoundScore = 0;
        for (Car* car : this->Cars) {
            int maxBonusTime = this->Duration - car->timeNeedToDrive();
            // Car can not finish in time
            if (maxBonusTime < 0)
                continue;

            upperBoundScore += maxBonusTime + this->BonusPerCar;
        }

        return upperBoundScore;
    }

    int removeUnusedStreets() {
        int removeStreets = 0;

        for (Intersection* intersection : Intersections) {
            for (int i = intersection->IncomingStreets.size() - 1; i >= 0; i--) {
                Street* inStreet = intersection->IncomingStreets[i];
                if (inStreet->IncomingUsageCount > 0)
                    continue;

                removeStreets++;
                intersection->IncomingStreets.erase(intersection->IncomingStreets.begin() + i);
            }
        }

        return removeStreets;
    }

    static Problem* loadProblem(string fileName)
    {
        int d, s, numberOfIntersections, v, f;
        map<string, Street*> streetsMap;

        ifstream sr(fileName);
        sr >> d;
        sr >> numberOfIntersections;
        sr >> s;
        sr >> v;
        sr >> f;

        Problem* problem = new Problem();
        problem->Duration = d;
        problem->BonusPerCar = f;

        // Load streets
        for (int streetId = 0; streetId < s; streetId++) {
            int start, end, length;
            string name;
            sr >> start;
            sr >> end;
            sr >> name;
            sr >> length;
            Street* street = new Street(streetId, start, end, name, length);
            streetsMap[name] = street;

            problem->Streets.push_back(street);
        }

        // Load cars
        for (int carId = 0; carId < v; carId++) {
            int p;
            sr >> p;
            vector<Street*> carStreets;
            for (int carStreet = 0; carStreet < p; carStreet++) {
                string streetName;
                sr >> streetName;
                carStreets.push_back(streetsMap[streetName]);
            }
            problem->Cars.push_back(new Car(carId, carStreets));
        }

        // Build intersections
        for (int i = 0; i < numberOfIntersections; i++)
            problem->Intersections.push_back(new Intersection(i));

        for (Street* street : problem->Streets) {
            problem->Intersections[street->StartIntersection]->OutgoingStreets.push_back(street);
            problem->Intersections[street->EndIntersection]->IncomingStreets.push_back(street);
        }

        // Count number of times a street is used as incoming street
        for (Car* car : problem->Cars)
            for (int i = 0; i < car->Streets.size() - 1; i++)
                car->Streets[i]->IncomingUsageCount++;

        // Update the number of cars on the street at the start
        for (Street* street : problem->Streets)
            street->CarsOnStart = 0;

        for (Car* car : problem->Cars)
            car->Streets[0]->CarsOnStart++;

        return problem;
    }
};

class GreenLightCycle {
public:
    int Duration;
    Street* MyStreet;

    // Temporary used during simulation
    bool GreenLightUsed;

    GreenLightCycle(Street* street, int duration) {
        this->MyStreet = street;
        this->Duration = duration;

        this->GreenLightUsed = false;
    }

    GreenLightCycle* clone() {
        return new GreenLightCycle(this->MyStreet, this->Duration);
    }
};

class SolutionIntersection {
public:
    int ID;
    vector<GreenLightCycle*> GreenLigths;

    // Temporary used during simulation
    int CurrentGreenLigth;
    int CurrentGreenLightChangeTime;
    int LastCarPassTime;

    // Temporary used during simulation
    vector<int> GreenLightsArray;

    SolutionIntersection(int id) {
        this->ID = id;
        CurrentGreenLightChangeTime = 0;
        CurrentGreenLigth = 0;
    }

    ~SolutionIntersection() {
        for (GreenLightCycle* g : GreenLigths)
            delete g;
    }

    SolutionIntersection* clone() {
        SolutionIntersection* solutionIntersection = new SolutionIntersection(this->ID);
        solutionIntersection->GreenLigths.resize(GreenLigths.size());
        for (int i = 0; i < GreenLigths.size(); i++)
            solutionIntersection->GreenLigths[i] = GreenLigths[i]->clone();

        return solutionIntersection;
    }

    void buildGreenLightsArray() {
        int greenLightsCycleDuration = 0;
        for (GreenLightCycle* greenLightCycle : GreenLigths)
            greenLightsCycleDuration += greenLightCycle->Duration;

        GreenLightsArray.clear();

        for (GreenLightCycle* greenLightCycle : GreenLigths) {
            for (int i = 0; i < greenLightCycle->Duration; i++)
                GreenLightsArray.push_back(greenLightCycle->MyStreet->UniqueID);
        }
    }

    int countGreenLights() {
        if (GreenLigths.size() == 0)
            return 0;

        int countGreenLights = 0;
        for (GreenLightCycle* greenLightCycle : GreenLigths)
            if (greenLightCycle->Duration > 0)
                countGreenLights++;

        return countGreenLights;
    }

    Street* getGreenLightStreet() {
        return GreenLigths[CurrentGreenLigth]->MyStreet;
    }

    bool hasGreenLights() {
        return countGreenLights() > 0;
    }
};

class Solution {
public:
    vector<SolutionIntersection*> Intersections;

    Solution(int numberOfIntersections) {
        Intersections.resize(numberOfIntersections);
        for (int i = 0; i < numberOfIntersections; i++)
            Intersections[i] = new SolutionIntersection(i);
    }

    Solution(Solution* other) {
        Intersections.resize(other->Intersections.size());
        for (int i = 0; i < other->Intersections.size(); i++)
            Intersections[i] = other->Intersections[i]->clone();
    }

    ~Solution() {
        for (SolutionIntersection* i : Intersections)
            delete i;
    }

    Solution* clone() {
        return new Solution(this);
    }

    int countIntersectionsWithGreenLights()
    {
        int count = 0;
        for (SolutionIntersection* intersection : Intersections)
            if (intersection->hasGreenLights())
                count++;

        return count;
    }
};

void initBasicSolution(Problem* problem, Solution* solution) {
    for (Intersection* i : problem->Intersections) {
        solution->Intersections[i->ID]->GreenLigths.clear();
        for (Street* street : i->IncomingStreets) {
            GreenLightCycle* cycle = new GreenLightCycle(street, 1);

            solution->Intersections[i->ID]->GreenLigths.push_back(cycle);
        }
    }
}

bool optimizeGreenLightOrder4_SortCars(CarSimultionPosition* a, CarSimultionPosition* b) {
    int aStreetsLeft = a->MyCar->Streets.size() - a->StreetNumber;
    int bStreetsLeft = b->MyCar->Streets.size() - b->StreetNumber;

    //if (aStreetsLeft == bStreetsLeft)
    //    return a->getCurrentStreet()->IncomingUsageCount < b->getCurrentStreet()->IncomingUsageCount;

    return aStreetsLeft > bStreetsLeft;
}

int optimizeGreenLightOrder4(Problem* problem, Solution* solution)
{
    //CarSimultionPositionByTimeGotHere carSimultionPositionByTimeGotHere = new CarSimultionPositionByTimeGotHere();

    int score = 0;
    int currentTime = 0;

    vector<CarSimultionPosition*> allSimulationCars;
    map<int, vector<CarSimultionPosition*>> carQueueByIntersection;

    // Create car queue in each intersection
    int simulationCarStart = -(int)(problem->Cars.size() + 1);
    for (Car* car : problem->Cars) {
        CarSimultionPosition* simulationCar = new CarSimultionPosition(car, simulationCarStart);
        allSimulationCars.push_back(simulationCar);
        carQueueByIntersection[car->Streets[0]->EndIntersection].push_back(simulationCar);
        simulationCarStart++;
    }

    // Init green lights
    for (SolutionIntersection* intersection : solution->Intersections) {
        intersection->CurrentGreenLigth = 0;
        if (intersection->GreenLigths.size() > 0)
            intersection->CurrentGreenLightChangeTime = intersection->GreenLigths[0]->Duration;
        else
            // Skip this
            intersection->CurrentGreenLightChangeTime = problem->Duration + 1;
    }

    unordered_set<int> firstCarPerStreetFound;
    vector<CarSimultionPosition*> firstCarPerStreet;

    while (currentTime <= problem->Duration)
    {
        // Update traffic lights cycle
        for (SolutionIntersection* intersection : solution->Intersections) {
            if (intersection->GreenLigths.size() == 0)
                continue;

            // Update intersection green light
            if (intersection->CurrentGreenLightChangeTime <= currentTime)
            {
                intersection->CurrentGreenLigth = (intersection->CurrentGreenLigth + 1) % intersection->GreenLigths.size();
                intersection->CurrentGreenLightChangeTime = currentTime + intersection->GreenLigths[intersection->CurrentGreenLigth]->Duration;
            }

            // Update intersection car
            vector<CarSimultionPosition*>* carQueue = &carQueueByIntersection[intersection->ID];

            // If it's possible to change the current green light - try selecting the best one
            if (!intersection->GreenLigths[intersection->CurrentGreenLigth]->GreenLightUsed)
            {
                firstCarPerStreetFound.clear();
                firstCarPerStreet.clear();

                for (int i = 0; i < carQueue->size(); i++)
                {
                    CarSimultionPosition* carSimultionPosition = (*carQueue)[i];
                    if (carSimultionPosition->TimeGotHere > currentTime)
                        break;

                    int streetId = carSimultionPosition->getCurrentStreet()->UniqueID;
                    if (firstCarPerStreetFound.find(streetId) == firstCarPerStreetFound.end())
                    {
                        firstCarPerStreetFound.insert(streetId);
                        firstCarPerStreet.push_back(carSimultionPosition);
                    }
                }

                if (firstCarPerStreet.size() == 0)
                    continue;

                sort(firstCarPerStreet.begin(), firstCarPerStreet.end(), optimizeGreenLightOrder4_SortCars);

                for (CarSimultionPosition* carSimultionPosition : firstCarPerStreet) {
                    // Find required green light
                    int requiredGreenLight = -1;
                    Street* street = carSimultionPosition->getCurrentStreet();
                    for (int g = 0; g < intersection->GreenLigths.size(); g++)
                        if (street->UniqueID == intersection->GreenLigths[g]->MyStreet->UniqueID) {
                            requiredGreenLight = g;
                            break;
                        }

                    // Required green light not found - skip
                    if (requiredGreenLight == -1)
                        continue;

                    // Required green light already used - skip
                    if (intersection->GreenLigths[requiredGreenLight]->GreenLightUsed)
                        continue;

                    // Swap possible only if it's the same green light duration
                    if (intersection->GreenLigths[requiredGreenLight]->Duration != intersection->GreenLigths[intersection->CurrentGreenLigth]->Duration)
                        continue;

                    // Swap green lights - now the car can continue!
                    GreenLightCycle* tmp = intersection->GreenLigths[requiredGreenLight];
                    intersection->GreenLigths[requiredGreenLight] = intersection->GreenLigths[intersection->CurrentGreenLigth];
                    intersection->GreenLigths[intersection->CurrentGreenLigth] = tmp;
                    tmp->GreenLightUsed = true;
                    break;
                }
            }

            bool carPassed = false;
            for (int i = 0; i < carQueue->size(); i++)
            {
                CarSimultionPosition* carSimultionPosition = (*carQueue)[i];
                if (carSimultionPosition->TimeGotHere > currentTime)
                    break;

                Street* street = carSimultionPosition->getCurrentStreet();
                if (carPassed)
                    continue;

                // Not green light
                if (street->UniqueID != intersection->getGreenLightStreet()->UniqueID)
                    continue;

                // Mark intersection as used for this cycle
                carPassed = true;

                intersection->GreenLigths[intersection->CurrentGreenLigth]->GreenLightUsed = true;

                // Process car green light
                carSimultionPosition->StreetNumber++;
                Street* newStreet = carSimultionPosition->getCurrentStreet();
                carSimultionPosition->TimeGotHere = currentTime + newStreet->Length;
                carSimultionPosition->TimeLeftOnDrive -= newStreet->Length;

                // Check if car finished
                carQueue->erase(carQueue->begin() + i);
                i--;

                if (carSimultionPosition->StreetNumber == carSimultionPosition->MyCar->Streets.size() - 1)
                {
                    // Check if finished on time - if so give bonus
                    if (carSimultionPosition->TimeGotHere <= problem->Duration)
                        score += problem->BonusPerCar + (problem->Duration - carSimultionPosition->TimeGotHere);
                }
                else
                {
                    // Car not finished - add it to the next intersection
                    insert_sorted(carQueueByIntersection[newStreet->EndIntersection], carSimultionPosition, CarSimultionPosition::compareByTimeGotHere);
                }
            }
        }

        currentTime++;
    }

    for (CarSimultionPosition* car : allSimulationCars)
        delete car;

    return score;
}

typedef CarSimultionPosition* PCarSimultionPosition;

static int binarySearch(vector<long>& arr, long key) {
    int mid;
    int lbound = 0;
    int ubound = arr.size() - 1;

    while (true) {
        mid = (lbound + ubound) / 2;
        if (lbound == ubound) {
            if (key >= arr[mid])
                return mid;
            return mid - 1;
        }
        else if (key == arr[mid])
            return mid;
        else if (key > arr[mid])
            lbound = mid + 1;
        else
            ubound = mid;
    }
}

static int binarySearch(PCarSimultionPosition* arr, int low, int high, int key)
{
    int mid;
    int lbound = low;
    int ubound = high;
    while (true) {
        mid = (lbound + ubound) / 2;
        if (lbound == ubound) {
            if (key > arr[mid]->TimeGotHere)
                return mid;
            return mid - 1;
        }
        else if (key == arr[mid]->TimeGotHere)
            return mid - 1;
        else if (key > arr[mid]->TimeGotHere)
            lbound = mid + 1;
        else
            ubound = mid;
    }
}

int runSimulationLite(Problem* problem, Solution* solution, PCarSimultionPosition* carSimultionPositionss) {
    int score = 0;
    int currentTime = 0;

    // Create list of cars in simulation
    int carSimultionPositionssSize = problem->Cars.size();
    int simulationCarStart = -(int)(carSimultionPositionssSize + 1);
    for (int i = 0; i < carSimultionPositionssSize; i++)
        carSimultionPositionss[i]->init(simulationCarStart++);

    // Init green lights
    for (SolutionIntersection* intersection : solution->Intersections) {
        intersection->buildGreenLightsArray();
        intersection->LastCarPassTime = -1;
    }

    while (currentTime <= problem->Duration)
    {
        // Update cars
        for (int i = 0; i < carSimultionPositionssSize; i++)
        {
            CarSimultionPosition* carSimultionPosition = carSimultionPositionss[i];
            if (carSimultionPosition->TimeGotHere > currentTime)
                break;

            //Street *street = carSimultionPosition->MyCar->Streets[carSimultionPosition->StreetNumber];

            SolutionIntersection* intersection = solution->Intersections[carSimultionPosition->StreetEndIntersection[carSimultionPosition->StreetNumber]];

            // Check if a car already used this intersection this cycle
            if (intersection->LastCarPassTime == currentTime)
                continue;

            if (intersection->GreenLightsArray.size() == 0)
                continue;

            int currentGreenLightStreetUniqueID = intersection->GreenLightsArray[currentTime % intersection->GreenLightsArray.size()];

            // Not green light, skip to next car
            if (carSimultionPosition->StreetUniqueID[carSimultionPosition->StreetNumber] != currentGreenLightStreetUniqueID)
                continue;

            // Mark intersection as used for this cycle
            intersection->LastCarPassTime = currentTime;

            // Process car green light
            carSimultionPosition->StreetNumber++;
            //            Street *newStreet = carSimultionPosition->getCurrentStreet();
            int newStreetLength = carSimultionPosition->StreetLength[carSimultionPosition->StreetNumber];
            carSimultionPosition->TimeGotHere = currentTime + newStreetLength;
            carSimultionPosition->TimeLeftOnDrive -= newStreetLength;

            // Check if car finished
            if (carSimultionPosition->StreetNumber == carSimultionPosition->MyCar->Streets.size() - 1)
            {
                // Check if finished on time - if so give bonus
                if (carSimultionPosition->TimeGotHere <= problem->Duration)
                    score += problem->BonusPerCar + (problem->Duration - carSimultionPosition->TimeGotHere);

                // Move to end
                carSimultionPosition->TimeGotHere = problem->Duration + 1;
                memmove(&carSimultionPositionss[i], &carSimultionPositionss[i + 1], (sizeof(PCarSimultionPosition)) * (carSimultionPositionssSize - (i + 1)));
                carSimultionPositionss[carSimultionPositionssSize - 1] = carSimultionPosition;

                i--;
            }
            else
            {
                // Add the car in the right place
                if (i + 1 < carSimultionPositionssSize) {
                    int newPos = binarySearch(carSimultionPositionss, i + 1, carSimultionPositionssSize - 1, carSimultionPosition->TimeGotHere);
                    if (newPos != i) {
                        memmove(&carSimultionPositionss[i], &carSimultionPositionss[i + 1], (sizeof(PCarSimultionPosition)) * (newPos - i));
                        carSimultionPositionss[newPos] = carSimultionPosition;
                        i--;
                    }
                }
            }
        }

        currentTime++;
    }

    return score;
}

int runSimulationLite(Problem* problem, Solution* solution) {
    PCarSimultionPosition* carSimultionPositionss = new PCarSimultionPosition[problem->Cars.size()];
    int carSimultionPositionssSize = problem->Cars.size();

    for (int i = 0; i < carSimultionPositionssSize; i++)
        carSimultionPositionss[i] = new CarSimultionPosition(problem->Cars[i], 0);

    int score = runSimulationLite(problem, solution, carSimultionPositionss);

    for (int i = 0; i < carSimultionPositionssSize; i++)
        delete carSimultionPositionss[i];
    delete[] carSimultionPositionss;

    return score;
}

void generateOutput(Solution* solution, string fileName) {
    stringstream sw;

    sw << solution->countIntersectionsWithGreenLights() << endl;

    for (SolutionIntersection* i : solution->Intersections) {
        // Count non-zero duration streets
        int streetCount = 0;
        for (GreenLightCycle* c : i->GreenLigths)
            if (c->Duration > 0)
                streetCount++;

        // Skip intersection - no streets
        if (streetCount == 0)
            continue;

        sw << i->ID << endl;
        sw << streetCount << endl;
        for (GreenLightCycle* c : i->GreenLigths)
            if (c->Duration > 0)
                sw << c->MyStreet->Name << " " << c->Duration << endl;
    }

    ofstream ofs;
    ofs.open(fileName);
    ofs << sw.str();
}

class MyRandom {
private:
    long State;

    void nextState() {
        State ^= State << 3;
        State ^= State >> 1;
        State ^= State << 11;
    }

public:
    MyRandom(long seed) {
        this->State = seed;
    }

    int nextInt(int n) {
        nextState();
        return abs((int)State) % n;
    }

    long nextLong(long n) {
        nextState();
        return abs(State) % n;
    }
};

class BruteForceSwap {
private:
    Problem* MyProblem;

    mutex BestSolutionMutex;
    Solution* BestSolution;
    int BestSolutionScore;
    long BestSolutionVersion;
    milliseconds OptimizationStartTime;

    long TotalWeight;
    vector<long> IntersectionWeighted;
    long ThreadNumber;
public:
    Solution* optimizeBruteForceSwap(Problem* problem, Solution* solution) {
        OptimizationStartTime = duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch());

        BestSolution = solution->clone();
        BestSolutionScore = runSimulationLite(problem, solution);
        BestSolutionVersion = 0;

        MyProblem = problem;

        IntersectionWeighted.clear();
        TotalWeight = 0;

        ThreadNumber = 0;
        for (int j = 0; j < solution->Intersections.size(); j++) {
            this->IntersectionWeighted.push_back(TotalWeight);

            long greenLightsLength = solution->Intersections[j]->GreenLigths.size();
            TotalWeight += greenLightsLength * greenLightsLength;
        }

        vector<thread> threads;
        for (int i = 0; i < 4; i++) {
            threads.push_back(thread(&BruteForceSwap::optimizeBruteForceSwapThread, this));
        }

        for (int i = 0; i < 4; i++)
            threads[i].join();

        return BestSolution;
    }

private:
    void optimizeBruteForceSwapThread() {
        int minDelta = 200;
        long lastUpdateSec = duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000;

        PCarSimultionPosition* carSimultionPositionss = new PCarSimultionPosition[MyProblem->Cars.size()];
        PCarSimultionPosition* tmpSimultionPositionss = new PCarSimultionPosition[MyProblem->Cars.size()];
        int carSimultionPositionssSize = MyProblem->Cars.size();
        for (int i = 0; i < carSimultionPositionssSize; i++)
            carSimultionPositionss[i] = new CarSimultionPosition(MyProblem->Cars[i], 0);


        BestSolutionMutex.lock();
        MyRandom random((++ThreadNumber) * time(NULL));
        Solution* threadBestSolution = BestSolution->clone();
        int threadBestSolutionScore = BestSolutionScore;
        long threadBestSolutionVersion = BestSolutionVersion;
        BestSolutionMutex.unlock();

        while (true) {
            long updateSec = duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000;
            if ((minDelta > 0) && (updateSec - lastUpdateSec > minDelta)) {
                minDelta = minDelta / 2;
                lastUpdateSec = updateSec;
                cout << "Min delta: " << minDelta << endl;
            }

            long item = random.nextLong(this->TotalWeight);
            int intersectionId = binarySearch(this->IntersectionWeighted, item);

            SolutionIntersection* intersection = threadBestSolution->Intersections[intersectionId];
            if (intersection->GreenLigths.size() < 2)
                continue;

            int a = random.nextInt(intersection->GreenLigths.size());
            int b = random.nextInt(intersection->GreenLigths.size());
            while (a == b)
                b = random.nextInt(intersection->GreenLigths.size());

            GreenLightCycle* tmp = intersection->GreenLigths[a];
            intersection->GreenLigths[a] = intersection->GreenLigths[b];
            intersection->GreenLigths[b] = tmp;

            memcpy(tmpSimultionPositionss, carSimultionPositionss, (sizeof(PCarSimultionPosition)) * carSimultionPositionssSize);
            int newScore = runSimulationLite(MyProblem, threadBestSolution, tmpSimultionPositionss);

            BestSolutionMutex.lock();
            if (newScore >= BestSolutionScore + minDelta) {
                lastUpdateSec = updateSec;

                delete BestSolution;
                BestSolution = threadBestSolution->clone();
                threadBestSolutionVersion = ++BestSolutionVersion;

                if (newScore > BestSolutionScore) {
                    milliseconds endTime = duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch());
                    cout << "New best: " << newScore << ",+" << newScore - BestSolutionScore << ", Intersection: " << intersectionId << ", Run time: " << (long)((endTime.count() - OptimizationStartTime.count()) / 1000) << endl;

                    generateOutput(BestSolution, OUTPUT_FILE);
                }
                threadBestSolutionScore = newScore;
                BestSolutionScore = newScore;
            }
            else {
                // Swap back
                GreenLightCycle* tmp = intersection->GreenLigths[a];
                intersection->GreenLigths[a] = intersection->GreenLigths[b];
                intersection->GreenLigths[b] = tmp;

                // Update with global best solution
                if (threadBestSolutionVersion < BestSolutionVersion) {
                    delete threadBestSolution;
                    threadBestSolution = BestSolution->clone();
                    threadBestSolutionScore = BestSolutionScore;
                    threadBestSolutionVersion = BestSolutionVersion;
                }
            }
            BestSolutionMutex.unlock();
        }

        for (int i = 0; i < carSimultionPositionssSize; i++)
            delete carSimultionPositionss[i];
        delete[] carSimultionPositionss;
        delete[] tmpSimultionPositionss;
    }
};

Solution* optimizeBruteForce(Problem* problem, Solution* solution) {
    Solution* bestSolution = solution;
    int lastScore = runSimulationLite(problem, solution);

    while (true) {
        BruteForceSwap bruteForce;
        Solution* newSolution = bruteForce.optimizeBruteForceSwap(problem, bestSolution);

        int newScore = runSimulationLite(problem, newSolution);
        if (newScore > lastScore) {
            delete bestSolution;
            bestSolution = newSolution;
            lastScore = newScore;
        }
        else {
            delete newSolution;
            break;
        }
    }

    return bestSolution;
}

int main(int argc, char** argv) {
    milliseconds startTime = duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch());

    Problem* problem = Problem::loadProblem(INPUT_FILE);

    int removeStreets = problem->removeUnusedStreets();
    cout << "Streets removed: " << removeStreets << endl;

    Solution* solution = new Solution(problem->Intersections.size());
    initBasicSolution(problem, solution);
    int score;
    score = optimizeGreenLightOrder4(problem, solution);
    cout << "Score after green light ordering: " << score << endl;

//    solution = optimizeBruteForce(problem, solution);

    //for (int i = 0; i < 100; i++)
    score = runSimulationLite(problem, solution);
    cout << "Score: " << score << endl;

    generateOutput(solution, OUTPUT_FILE);

    milliseconds endTime = duration_cast<milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    cout << "Run time: " << (long)(endTime.count() - startTime.count()) << endl;

    delete problem;
    delete solution;

    return 0;
}