
// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "CommonCrypto",
    products: [
        // Products define the executables and libraries produced by a package, and make them visible to other packages.
        .library(
            name: "CommonCrypto",
            targets: ["CommonCrypto"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
        //.package(url: "https://github.com/amraboelela/CLevelDB", .branch("master"))
    ],
    targets: [
        .systemLibrary(name: "CommonCrypto", path: "."),
    ]
)
