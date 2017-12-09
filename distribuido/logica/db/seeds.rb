# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rails db:seed command (or created alongside the database with db:setup).
#
# Examples:
#
#   movies = Movie.create([{ name: 'Star Wars' }, { name: 'Lord of the Rings' }])
#   Character.create(name: 'Luke', movie: movies.first)
require 'sepa_api'

sepa = SepaApi.new

sepa.guardarPeriodos
sepa.getAsignaturasInformatica

docentes = Docente.all
docentes.each do |docente|
  bloques = 0
  cursos = docente.cursos
  cursos.each do |curso|
    bloques+=curso.horarios.size
  end
  docente.bloques = bloques
  docente.save
end

acceso = AccesoParalelo.new
acceso.save