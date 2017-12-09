class AddAsignadoToCursosAndRenameOcupadoToLibreOnDisponibilidad < ActiveRecord::Migration[5.0]
  def change
    add_column :cursos , :asignado ,:boolean, default:  false
    rename_column :disponibilidad_salas, :ocupado , :libre
  end
end
