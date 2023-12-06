
#include <fstream>
#include <mlx-analytics.h>
#include <time/snx-time.h>
#include <mobility/node-mobility.h>
#include <mobility/earth-reference.h>

#include <mlx-runge-kutta.h>
#include <mobility/keplerian-propagator.h>




static mlx::MlxVector<double> RK4Step(const mlx::MlxVector<double>& u)
{
    mlx::MlxVector<double> du(4);

    du[0] = u.at(2);
    du[1] = u.at(3);

    double r = sqrt(u.at(0) * u.at(0) + u.at(1) * u.at(1));
    double f = snx::EARTH_GM / pow(r, 3);

    du[2] = -f * u.at(0);
    du[3] = -f * u.at(1);

    return du;
}



int main(int args, char* argv[] )
{

    snx::TrajectoryParameterSet prams(55.5, 0.5, 400, 0, 0, 0);
    snx::UnperturbedKeplerianPropagator prop(&prams);

    std::ofstream fout("./test-runge-out.txt");
    prop.plotOrbit(&fout);
    fout.close();



    //lx::MlxRungeKuttaIntegration prop(4);
    /*
    prop.setStepFunction(RK4Step);

    // x0=6771000.0; y0=0.0; vx0=-0.0; vy0=9396.97584579858

    mlx::MlxVector<double> u_init(4);
    u_init[0] = 6771000.0;
    u_init[1] = 0.0;
    u_init[2] = -0.0;
    u_init[3] = 9396.97584579858;


    mlx::MlxVector<double> y(4);
    mlx::MlxVector<double> u(u_init);


    double T;
    double T_end = tspan * 1.2;
    while ((T += dt) < T_end)
    {
        prop.step(u, dt, &y);

        fout << y.at(0) << "\t" << y.at(1) << "\t" << y.at(2) << "\t" << y.at(3) << "\n";
        u = y;
    }
    


    */


    return 0;
}