#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("tri-mult-poly-program");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("An Algorithm for Triangulating Multiple 3D Polygons");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source .curve file"));


    // A boolean option with multiple names (-d, --useDT)
    QCommandLineOption useDT(QStringList() << "d" << "useDT",
            QCoreApplication::translate("main", "search in Delaunay triangle space"));
    parser.addOption(useDT);

    // A boolean option with multiple names (-m, --useMinSet)
    QCommandLineOption useMinSet(QStringList() << "u" << "useMinSet",
            QCoreApplication::translate("main", "use minimal set to speed up the algorithm"));
    parser.addOption(useMinSet);

    // A boolean option with multiple names (-a, --areaWeight)
    QCommandLineOption areaWeight(QStringList() << "a" << "areaWeight",
            QCoreApplication::translate("main", "use area metric"));
    parser.addOption(areaWeight);

    // A boolean option with multiple names (-e, --edgeWeight)
    QCommandLineOption edgeWeight(QStringList() << "e" << "edgeWeight",
            QCoreApplication::translate("main", "use perimeter metric"));
    parser.addOption(edgeWeight);


    // A boolean option with multiple names (-i, --dihedralWeight)
    QCommandLineOption dihedralWeight(QStringList() << "i" << "dihedralWeight",
            QCoreApplication::translate("main", "use average dihedral metric"));
    parser.addOption(dihedralWeight);


    // A boolean option with multiple names (-n, --useMinMaxDihedral)
    QCommandLineOption useMinMaxDihedral(QStringList() << "n" << "useMinMaxDihedral",
            QCoreApplication::translate("main", "each pair of adjacent mesh triangles"));
    parser.addOption(useMinMaxDihedral);

    // A boolean option with multiple names (-s, --saveObj)
    QCommandLineOption saveObj(QStringList() << "s" << "saveObj",
            QCoreApplication::translate("main", "save surface"));
    parser.addOption(saveObj);


    // A boolean option with multiple names (-n, --useNormal)
    QCommandLineOption useNormal(QStringList() << "n" << "useNormal",
            QCoreApplication::translate("main", "include in normal file"));
    parser.addOption(useNormal);



    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();

    QString sourceValue = args[0];

    bool useDTValue = parser.isSet(useDT);
    bool useMinSetValue = parser.isSet(useMinSet);
    bool areaWeightValue = parser.isSet(areaWeight);
    bool edgeWeightValue = parser.isSet(edgeWeight);
    bool dihedralWeightValue = parser.isSet(dihedralWeight);
    bool useMinMaxDihedralValue = parser.isSet(useMinMaxDihedral);
    bool saveObjValue = parser.isSet(saveObj);
    bool useNormalValue = parser.isSet(useNormal);
}
