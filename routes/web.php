<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\PlanningController; // Zorg ervoor dat je dit toevoegt

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
})->name('welcome');

Route::get('/page1', function () {
    return view('page1');
})->name('page1');

Route::post('/plannings', [PlanningController::class, 'store'])->name('plannings.store');
Route::get('/planning/show', [PlanningController::class, 'show'])->name('planning.show');
Route::get('/page1', [PlanningController::class, 'index'])->name('page1');
Route::delete('/plannings/{id}', [PlanningController::class, 'destroy'])->name('plannings.destroy');
Route::post('/plannings/replicate/{id}', [PlanningController::class, 'replicate'])->name('plannings.replicate');


